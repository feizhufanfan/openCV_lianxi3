#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
class Draw_img {

public:
	void Draw_line(Mat &img);
	void Draw_Rectangle(Mat &img);
	void Draw_Circle(Mat &img);
	void Draw_Ellipse(Mat &img);
	void Draw_FillPoly(Mat &img);//多边矩形
	void Draw_Poly(Mat &img);
	void Draw_world(Mat &img);
};
void Draw_img::Draw_world(Mat &img){
	
	putText(img,"hello_openCV",Point(100,img.rows-20), FONT_HERSHEY_SCRIPT_SIMPLEX,2,Scalar(64,64,64),3);
}
void Draw_img::Draw_FillPoly(Mat &img) {
	Point arry[1][3];
	arry[0][0] = Point(100, 100);
	arry[0][1] = Point(100, 200);
	arry[0][2] = Point(200, 100);
	/*arry[0][3] = Point(img.cols/2-20,img.rows/2-20);
	arry[0][4] = Point(img.cols/4-50,img.rows/4-50);
	arry[0][5] = Point(img.cols/4-20,img.rows/4-20);*/
	const Point* pts[] = { arry[0] };
	int npts[] = { 3 };
	fillPoly(img,pts,npts,1,Scalar(255,255,0));
}
void Draw_img::Draw_Poly(Mat &img){
	Point arry[1][3];
	arry[0][0] = Point(10,10);
	arry[0][1] = Point(10,20);
	arry[0][2] = Point(20,10);
	/*arry[0][3] = Point(img.cols/2-20,img.rows/2-20);
	arry[0][4] = Point(img.cols/4-50,img.rows/4-50);
	arry[0][5] = Point(img.cols/4-20,img.rows/4-20);*/
	const Point* pts[] = { arry[0] };
	int npts[] = { 3 };
	polylines(img,pts,npts,1,true,Scalar(25,50,60),1,8);
}
void Draw_img::Draw_Ellipse(Mat &img){
	
	
	ellipse(img,Point(img.cols/2,img.rows/2),Size(30,40),90,0,270,Scalar(0,0,255));
}

void Draw_img::Draw_Circle(Mat &img){
	Point p = Point(img.size()/2);
	circle(img,p,20,Scalar(0,255,0),2,8);
}
void Draw_img::Draw_line(Mat &img) {
	Point p[2];
	p[0] = Point(img.cols /4, img.rows / 4);
	p[1] = Point(img.cols/2,img.rows/2);
	line(img,p[0],p[1],Scalar(128,128,128),2,LINE_8);
}
void Draw_img::Draw_Rectangle(Mat &img) {
	Rect rect = Rect((int)img.cols*0.9,(int)img.rows*0.9,10,10);
	rectangle(img,rect,Scalar(255,0,0),2,8);
}

int main(int argc,char** argv) {
	Mat src1;
	Draw_img a;
	//src1 = imread("G:/picture/pic/q1.jpg");
	//src1.create(Size(200,200),CV_8UC3,);
	src1 = Mat(500,500,CV_8UC3,Scalar(0,0,0));
	//if (!src1.data) {
	//	cout << "文件为空！";
	//	return 0;
	//}
	//resize(src1,src1,src1.size()/2);
	a.Draw_line(src1);
	a.Draw_Rectangle(src1);
	a.Draw_Circle(src1);
	a.Draw_Ellipse(src1);
	a.Draw_Poly(src1);
	a.Draw_FillPoly(src1);
	a.Draw_world(src1);
	cout << src1.size(); 



	namedWindow("src1",WINDOW_AUTOSIZE);
	imshow("src1",src1);
	waitKey(0);
	return 0;
}
