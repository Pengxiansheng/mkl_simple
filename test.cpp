#define EIGEN_USE_MKL_ALL

#include <stdio.h>
#include <Eigen/Dense>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  
    Eigen::MatrixXd P(100, 100); 
    P = Eigen::MatrixXd::Random(100, 100);
    Eigen::MatrixXd Pinv_(100, 100);
    Pinv_.setIdentity();

    clock_t start;  
    double _time;            
    cout << "=================" << endl; 
    start = clock(); 
    P.llt().solveInPlace(Pinv_);
    //cout << P * Pinv_ << endl; // 出来有可能不是单位阵，可以找我交流来修改
    _time = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "llt:     " << _time * 1000 << "ms" << endl;  
    cout << "=================" << endl;
    start = clock(); 
    Pinv_ = P.inverse();
    //cout << P * Pinv_ << endl;
    _time = (double)(clock() - start) / CLOCKS_PER_SEC;  
    cout << "inverse: " << _time * 1000 << "ms" << endl;
    cout << "=================" << endl;

}
