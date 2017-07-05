#include "MyForm.h"

// TrainAndTest.cpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>

#include<iostream>
#include<sstream>
using namespace System;
using namespace System::Windows::Forms;

[System::STAThread]
int main() {
	j::MyForm mForm;
	
	Application::Run(%mForm);
	return(0);
}

