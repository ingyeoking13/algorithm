#include <opencv2/opencv.hpp>

using namespace cv;
using namespace cv::ml;

//class for digit recognition 
class DigitRecognizer {
	public:
		DigitRecognizer();
		~DigitRecognizer();
		bool train(char* trainPath, char* labelsPath);
		int classify(Mat img);

	private:
		Mat preprocessImage(Mat img);
		int readFlippedInteger(FILE *fp);

	private:
		KNearest    *knn;
		int numRows, numCols, numImages;
};
