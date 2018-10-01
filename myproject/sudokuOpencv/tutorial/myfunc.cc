#include <opencv2/opencv.hpp>

using namespace cv;

//merge lines so can find out exactly where the puzzle is.
void mergeLines(std::vector<Vec2f> *lines, Mat &img){
	std::vector<Vec2f>::iterator cur;
	for (cur=lines->begin();cur!=lines->end();cur++){

		//check a line whether it has been already fused.
		if((*cur)[0]==0 && (*cur)[1]==-100) continue;

		//we use two variable to find a two point
		float rho= (*cur)[0], theta = (*cur)[1];

		Point pt1cur, pt2cur;
		if(theta>CV_PI*45/180 && theta<CV_PI*135/180) {
			pt1cur.x=0, pt1cur.y=rho/sin(theta);
			pt2cur.x=img.size().width, pt2cur.y=-pt2cur.x/tan(theta) + rho/sin(theta);
		}
		else {
			pt1cur.y=0, pt1cur.x=rho/cos(theta);
			pt2cur.y=img.size().height, pt2cur.x=-pt2cur.y/tan(theta) + rho/cos(theta);
		}

		//now we iterating over the lines again.
		//with this loop, we can compare every line with every other line.
		//if we find that the line current is the same as the line pos, then we skip.
		std::vector<Vec2f>::iterator pos;
		for(pos=lines->begin();pos!=lines->end();pos++){ 
			if(*cur==*pos) continue; 

			//now we check if the lines are withing a certain distance of each other
			//if they are, we store the rho and theta for the line pos and find two points on the line pos.
			if(fabs((*pos)[0]-(*cur)[0])<20 && fabs((*pos)[1]-(*cur)[1])<CV_PI*10/180) {

				rho = (*pos)[0], theta = (*pos)[1];

				Point pt1, pt2;
				if((*pos)[1]>CV_PI*45/180 && (*pos)[1]<CV_PI*135/180) {
					pt1.x=0, pt1.y = rho/sin(theta);
					pt2.x=img.size().width, pt2.y=-pt2.x/tan(theta) + rho/sin(theta);
				}
				else {
					pt1.y=0, pt1.x=rho/cos(theta);
					pt2.y=img.size().height, pt2.x=-pt2.y/tan(theta) + rho/cos(theta);
				}

				//if endpoints of the line pos and the line current are close to each other, we fuse them.
				if(((double)(pt1.x-pt1cur.x)*(pt1.x-pt1cur.x) + (pt1.y-pt1cur.y)*(pt1.y-pt1cur.y)<64*64) &&
						((double)(pt2.x-pt2cur.x)*(pt2.x-pt2cur.x) + (pt2.y-pt2cur.y)*(pt2.y-pt2cur.y)<64*64)) {
						// Merge the two and set pos's rho and theata to unavailable status.
						(*cur)[0] = ((*cur)[0]+(*pos)[0])/2;
						(*cur)[1] = ((*cur)[1]+(*pos)[1])/2;
						(*pos)[0]=0; (*pos)[1]=-100;
				}
			}
		}
	}
}

void drawLine(Vec2f line, Mat &img, Scalar rgb = CV_RGB(0,0,255)) {
	if(line[1]!=0) {
			float m = -1/tan(line[1]), c = line[0]/sin(line[1]);
			cv::line(img, Point(0, c), Point(img.size().width, m*img.size().width+c), rgb);
	}
	else cv::line(img, Point(line[0], 0), Point(line[0], img.size().height), rgb);
}
