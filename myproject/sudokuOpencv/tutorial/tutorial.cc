#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void drawLine(Vec2f line, Mat &img, Scalar rgb = CV_RGB(0,0,255)) {
	if(line[1]!=0) {
			float m = -1/tan(line[1]), c = line[0]/sin(line[1]);
			cv::line(img, Point(0, c), Point(img.size().width, m*img.size().width+c), rgb);
	}
	else cv::line(img, Point(line[0], 0), Point(line[0], img.size().height), rgb);
}

//merge lines so can find out exactly where the puzzle is.
void mergeLines(std::vector<Vec2f> *lines, Mat &img){
	std::vector<Vec2f>::iterator cur;
	for (cur=lines->begin();cur!=lines->end();cur++){
		if((*current)[0]==0 && (*current)[1]==-100) continue;
		float p1 = (*current)[0], theta1 = (*current)[1];
		Point pt1current, pt2current;
		if(theta1>CV_PI*45/180 && theta1<CV_PI*135/180) {
			pt1current.x=0;
			pt1current.y = p1/sin(theta1);
			pt2current.x=img.size().width;
			pt2current.y=-pt2current.x/tan(theta1) + p1/sin(theta1);
		}
		else {
			pt1current.y=0;
			pt1current.x=p1/cos(theta1);
			pt2current.y=img.size().height;
			pt2current.x=-pt2current.y/tan(theta1) + p1/cos(theta1);
		}
	}
}

int main(){
	//read image and check it
	Mat image = imread("sudoku.jpg", 0);
	if ( !image.data ) { printf("No image data \n"); return -1; }
	namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);
	waitKey(0);

	Mat outerBox = Mat(image.size(), CV_8UC1);
	GaussianBlur(image, image, Size(11,11), 0);
	adaptiveThreshold(image, outerBox, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 2);
	bitwise_not(outerBox, outerBox);

	Mat kernel = (Mat_<uchar>(3,3) << 0,1,0,1,1,1,0,1,0);
	dilate(outerBox, outerBox, kernel);

	//finding the biggest blob with floodfill function
	int max=-1; 
	Point maxPt;

	for(int y=0;y<outerBox.size().height;y++) {
		uchar *row = outerBox.ptr(y);
		for(int x=0;x<outerBox.size().width;x++) {
			if(row[x]>=128) { 
				int area = floodFill(outerBox, Point(x,y), CV_RGB(0,0,64)); 
				if(area>max) {
					maxPt = Point(x,y);
					max = area;
				}
			}
		}
	}

	imshow("floodfill", outerBox);
	waitKey(0);
	//we have several blobs filled with a dark gray colour(64) and we also know the
	//point what produces a blob with maximum area. so we floodfill that point with white
	floodFill(outerBox, maxPt, CV_RGB(255,255,255));

	imshow("floodfill again", outerBox);
	waitKey(0);

	//now, the biggest blob is white. we need to turn the other blobs black.
	for(int y=0;y<outerBox.size().height;y++) {
		uchar *row = outerBox.ptr(y);
		for(int x=0;x<outerBox.size().width;x++) {
			if(row[x]==64 && x!=maxPt.x && y!=maxPt.y) {
				int area = floodFill(outerBox, Point(x,y), CV_RGB(0,0,0));
			}
		}
	}

	imshow("biggest one remained white, others turn to black", outerBox);
	waitKey(0);

	//restore image from dilated one.
	erode(outerBox, outerBox, kernel);
	imshow("thresholded", outerBox);
	waitKey(0);

	//detecting lines with hough transfrom
	std::vector<Vec2f> lines;
	HoughLines(outerBox, lines, 1, CV_PI/180, 200);

  for(int i=0;i<lines.size();i++)  
		drawLine(lines[i], outerBox, CV_RGB(0,0,128)); 

	imshow("detecting lines", outerBox);
	waitKey(0);

	return 0;
}
