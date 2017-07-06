#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>


namespace j {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	class ContourWithData {
	public:
		std::vector<cv::Point> ptContour;           
		cv::Rect boundingRect;                      
		float fltArea;                             

		bool checkIfContourIsValid() {                           
			if (fltArea < 20) return false;           
			return true;                                            
		}

		static bool sortByBoundingRectXPosition(const ContourWithData& cwdLeft, const ContourWithData& cwdRight) {      
			return(cwdLeft.boundingRect.x < cwdRight.boundingRect.x);                                                  
		}

	};
	
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  equation;
	private: System::Windows::Forms::Label^  x1;
	private: System::Windows::Forms::Label^  x2;
	private: System::Windows::Forms::Label^  nameOfPicture;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  x12;
	private: System::Windows::Forms::Label^  rx1;
	private: System::Windows::Forms::Label^  rx2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->equation = (gcnew System::Windows::Forms::Label());
			this->x1 = (gcnew System::Windows::Forms::Label());
			this->x2 = (gcnew System::Windows::Forms::Label());
			this->nameOfPicture = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->x12 = (gcnew System::Windows::Forms::Label());
			this->rx1 = (gcnew System::Windows::Forms::Label());
			this->rx2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"upload image";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 36);
			this->button2->TabIndex = 2;
			this->button2->Text = L"start recognition";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(242, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"recognized equation:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(242, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"x1:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(242, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"x2:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(242, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"graphics:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// equation
			// 
			this->equation->AutoSize = true;
			this->equation->Location = System::Drawing::Point(363, 20);
			this->equation->Name = L"equation";
			this->equation->Size = System::Drawing::Size(0, 13);
			this->equation->TabIndex = 7;
			this->equation->Click += gcnew System::EventHandler(this, &MyForm::equation_Click);
			// 
			// x1
			// 
			this->x1->AutoSize = true;
			this->x1->Location = System::Drawing::Point(283, 46);
			this->x1->Name = L"x1";
			this->x1->Size = System::Drawing::Size(0, 13);
			this->x1->TabIndex = 8;
			this->x1->Click += gcnew System::EventHandler(this, &MyForm::x1_Click);
			// 
			// x2
			// 
			this->x2->AutoSize = true;
			this->x2->Location = System::Drawing::Point(283, 68);
			this->x2->Name = L"x2";
			this->x2->Size = System::Drawing::Size(0, 13);
			this->x2->TabIndex = 9;
			this->x2->Click += gcnew System::EventHandler(this, &MyForm::x2_Click);
			// 
			// nameOfPicture
			// 
			this->nameOfPicture->AutoSize = true;
			this->nameOfPicture->Location = System::Drawing::Point(21, 46);
			this->nameOfPicture->Name = L"nameOfPicture";
			this->nameOfPicture->Size = System::Drawing::Size(0, 13);
			this->nameOfPicture->TabIndex = 10;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(286, 106);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(271, 231);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// x12
			// 
			this->x12->AutoSize = true;
			this->x12->BackColor = System::Drawing::Color::White;
			this->x12->Location = System::Drawing::Point(414, 247);
			this->x12->Name = L"x12";
			this->x12->Size = System::Drawing::Size(0, 13);
			this->x12->TabIndex = 12;
			// 
			// rx1
			// 
			this->rx1->AutoSize = true;
			this->rx1->BackColor = System::Drawing::Color::White;
			this->rx1->Location = System::Drawing::Point(328, 237);
			this->rx1->Name = L"rx1";
			this->rx1->Size = System::Drawing::Size(0, 13);
			this->rx1->TabIndex = 13;
			// 
			// rx2
			// 
			this->rx2->AutoSize = true;
			this->rx2->BackColor = System::Drawing::Color::White;
			this->rx2->Location = System::Drawing::Point(488, 237);
			this->rx2->Name = L"rx2";
			this->rx2->Size = System::Drawing::Size(0, 13);
			this->rx2->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(593, 368);
			this->Controls->Add(this->rx2);
			this->Controls->Add(this->rx1);
			this->Controls->Add(this->x12);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->nameOfPicture);
			this->Controls->Add(this->x2);
			this->Controls->Add(this->x1);
			this->Controls->Add(this->equation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Quadratic equation";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		std::vector<ContourWithData> allContoursWithData;
		std::vector<ContourWithData> validContoursWithData;
		cv::Mat matClassificationInts;
		cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::READ);

		if (fsClassifications.isOpened() == false) {
			std::cout << "Error with opening file: classifications.xml\n";                                                                            
		}

		fsClassifications["classifications"] >> matClassificationInts;
		fsClassifications.release();

		cv::Mat matTrainingImagesAsFlattenedFloats;
		cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::READ);
		if (fsTrainingImages.isOpened() == false) {
			std::cout << "Error with opening file: images.xml\n";

		}

		fsTrainingImages["images"] >> matTrainingImagesAsFlattenedFloats;
		fsTrainingImages.release();


		cv::Ptr<cv::ml::KNearest>  kNearest(cv::ml::KNearest::create());
		kNearest->train(matTrainingImagesAsFlattenedFloats, cv::ml::ROW_SAMPLE, matClassificationInts);


		cv::Mat matTestingNumbers;
		if (getFilename() != "") {
			 matTestingNumbers = cv::imread(getFilename());
		}
		else {
			std::cout << "Pick an image!\n";         
		}


		cv::Mat matGrayscale;          
		cv::Mat matBlurred;            
		cv::Mat matThresh;              
		cv::Mat matThreshCopy;         

		cv::cvtColor(matTestingNumbers, matGrayscale, CV_BGR2GRAY);      
																			
		cv::GaussianBlur(matGrayscale,              
			matBlurred,               
			cv::Size(5, 5),           
			0);                     
		cv::adaptiveThreshold(matBlurred,                         
			matThresh,                          
			255,                               
			cv::ADAPTIVE_THRESH_GAUSSIAN_C,      
			cv::THRESH_BINARY_INV,               
			11,                                
			2);                                 

		matThreshCopy = matThresh.clone();            

		std::vector<std::vector<cv::Point> > ptContours;       
		std::vector<cv::Vec4i> v4iHierarchy;                   

		cv::findContours(matThreshCopy,            
			ptContours,                           
			v4iHierarchy,                        
			cv::RETR_EXTERNAL,                     
			cv::CHAIN_APPROX_SIMPLE);              

		for (int i = 0; i < ptContours.size(); i++) {               
			ContourWithData contourWithData;                                                  
			contourWithData.ptContour = ptContours[i];                                        
			contourWithData.boundingRect = cv::boundingRect(contourWithData.ptContour);        
			contourWithData.fltArea = cv::contourArea(contourWithData.ptContour);              
			allContoursWithData.push_back(contourWithData);                                    
		}

		for (int i = 0; i < allContoursWithData.size(); i++) {                      
			if (allContoursWithData[i].checkIfContourIsValid()) {                 
				validContoursWithData.push_back(allContoursWithData[i]);          
			}
		}
		std::sort(validContoursWithData.begin(), validContoursWithData.end(), ContourWithData::sortByBoundingRectXPosition);

		std::string strFinalString;


		for (int i = 0; i < validContoursWithData.size(); i++) {            

																			
			cv::rectangle(matTestingNumbers,                           
				validContoursWithData[i].boundingRect,       
				cv::Scalar(0, 255, 0),                       
				2);                                         

			cv::Mat matROI = matThresh(validContoursWithData[i].boundingRect);        

			cv::Mat matROIResized;
			cv::resize(matROI, matROIResized, cv::Size(10, 15));    

			cv::Mat matROIFloat;
			matROIResized.convertTo(matROIFloat, CV_32FC1);             

			cv::Mat matROIFlattenedFloat = matROIFloat.reshape(1, 1);

			cv::Mat matCurrentChar(0, 0, CV_32F);

			kNearest->findNearest(matROIFlattenedFloat, 1, matCurrentChar);    

			float fltCurrentChar = (float)matCurrentChar.at<float>(0, 0);

			strFinalString = strFinalString + char(int(fltCurrentChar));      
		}

		std::cout <<"Equation : " << strFinalString << "\n";      

		cv::imshow("matTestingNumbers", matTestingNumbers);     

		String^ strEq = gcnew String(strFinalString.c_str());
		
		this->equation->Text = strEq;
		int num = 0;
		int x = 0;
		int x2 = 0;
		std::string letter="";
		for (std::string::size_type i = 0; i < strFinalString.size(); ++i) {
			if (47 < (int)strFinalString[i] && (int)strFinalString[i]<58) {	
				int b= strFinalString[i]-48;
				if (i > 0 && i!=strFinalString.size()-1) {
					if ((strFinalString[i - 1].Equals('+') || strFinalString[i - 1].Equals('-') || strFinalString[i - 1].Equals('=')) && ((int)strFinalString[i+1]<97)) {	
						std::string toAs = strFinalString.substr(i);

						if (toAs.find('=') != std::string::npos) {	
							if (strFinalString[i - 1].Equals('+')) {
								num += b;
							}
							else if (strFinalString[i - 1].Equals('-')) {
								num -= b;
							}							
						}
						else {
							if (strFinalString[i - 1].Equals('-')) {
								num += b;
							}else if (strFinalString[i - 1].Equals('+') || strFinalString[i-1].Equals('=')) {
								num -= b;
							}

						}
					}
				}
				else {
					if (i == 0) {
						if ((int)strFinalString[i + 1] < 97) {	
							num += b;
						}
					}
					else {
						if (strFinalString[i - 1].Equals('+') || strFinalString[i - 1].Equals('=')) {
							num -= b;
						}
						else if(strFinalString[i-1].Equals('-')){
							num += b;
						}
					
					}
				}
			}
			else if(!strFinalString[i].Equals('+') && !strFinalString[i].Equals('-') && !strFinalString[i].Equals('=')){
				std::string firstLetter(1, strFinalString[i]);
				if (letter.compare(firstLetter)==0 || letter.size()==0) {
					letter = strFinalString[i];
				}
				else {
					
					std::cout << "Mora postojati samo jedna promenljiva!!\n";
					return;
				}
			}
		}

		std::cout << "prepoznata promenljiva : " << letter<<'\n';
		std::size_t asi = strFinalString.find('=');

		std::string::size_type start_pos = 0;
		while (std::string::npos !=
			(start_pos = strFinalString.find(letter+'2', start_pos)))
		{

			if (start_pos < asi) {
					if (start_pos != 0) {
					if (strFinalString[start_pos - 1].Equals('-')) {
						x2--;
					}
					else if (strFinalString[start_pos - 1].Equals('+')) {
						x2++;
					}
					else {
						if ((int)strFinalString[start_pos - 1] < 58 && (int)strFinalString[start_pos - 1]>47) {
							if (start_pos != 1) {
								if ((int)strFinalString[start_pos - 2].Equals('+')) {
									x2 += (int)strFinalString[start_pos - 1] - 48;
								}
								else if ((int)strFinalString[start_pos - 2].Equals('-')) {
									x2 -= (int)strFinalString[start_pos - 1] - 48;
								}
							}
							else {
								x2 += (int)strFinalString[start_pos - 1] - 48;
							}
						}
					}

				}
				else {
					x2++;
				}
			}
			else {
				if (strFinalString[start_pos-1].Equals('=')) {
					x2--;
				}
				else if(strFinalString[start_pos - 1].Equals('-')) {
					x2++;
				}
				else if (strFinalString[start_pos - 1].Equals('+')) {
					x2--;
				}else {
					if ((int)strFinalString[start_pos - 1] < 58 && (int)strFinalString[start_pos - 1]>47) {
						if ((int)strFinalString[start_pos - 2].Equals('+')) {
							x2 -= (int)strFinalString[start_pos - 1]-48;
						}
						else if((int)strFinalString[start_pos - 2].Equals('-')) {
							x2 += (int)strFinalString[start_pos - 1] - 48;
						}
						else {
							x2-= (int)strFinalString[start_pos - 1] - 48;
						}
					}
				}
			}
			++start_pos;
		}


		start_pos = 0;
		while (std::string::npos !=
			(start_pos = strFinalString.find(letter, start_pos)))
		{
			if (start_pos != strFinalString.size()) {
				if (!strFinalString[start_pos + 1].Equals('2')) {
					if (start_pos < asi) {
						if (start_pos != 0) {
							if (strFinalString[start_pos - 1].Equals('-')) {
								x--;
							}
							else if (strFinalString[start_pos - 1].Equals('+')) {
								x++;
								}
							else {
								if ((int)strFinalString[start_pos - 1] < 58 && (int)strFinalString[start_pos - 1]>47) {
									if ((int)strFinalString[start_pos - 2].Equals('+')) {
										x += (int)strFinalString[start_pos - 1] - 48;
									}
									else if ((int)strFinalString[start_pos - 2].Equals('-')) {
										x -= (int)strFinalString[start_pos - 1] - 48;
									}
								}
							}

						}
						else {
							x++;
						}
					}
					else {
						if (strFinalString[start_pos - 1].Equals('=')) {
							x--;
						}
						else if (strFinalString[start_pos - 1].Equals('-')) {
							x++;
						}
						else if (strFinalString[start_pos - 1].Equals('+')) {
							x--;
						}
						else {
							if ((int)strFinalString[start_pos - 1] < 58 && (int)strFinalString[start_pos - 1]>47) {
								if ((int)strFinalString[start_pos - 2].Equals('+')) {
									x -= (int)strFinalString[start_pos - 1] - 48;
								}
								else if ((int)strFinalString[start_pos - 2].Equals('-')) {
									x += (int)strFinalString[start_pos - 1] - 48;
								}
								else {
									x -= (int)strFinalString[start_pos - 1] - 48;
								}
							}
						}
					}
				}
			}
		++start_pos;
			
		}
		
		std::cout << letter<<"2 :" << x2 << '\n';
		std::cout << letter<<" :" << x << '\n';
		std::cout << " num: " << num << '\n';
		
		float D = float(sqrt(pow(x, 2) - 4 * num*x2));
		if (D > 0) {

			float resenje1 = float(-x + float(sqrt(pow(x, 2) - 4 * num*x2))) / float(2 * x2);
			float resenje2 = float(-x - float(sqrt(pow(x, 2) - 4 * num*x2))) / float(2 * x2);

			this->x12->Text = "";
			if (x2 >= 0) {
				if (resenje1 < resenje2) {
					this->rx1->Text = Convert::ToString(resenje1);
					this->rx2->Text = Convert::ToString(resenje2);
				}
				else {
					this->rx1->Text = Convert::ToString(resenje2);
					this->rx2->Text = Convert::ToString(resenje1);
				}
				this->pictureBox1->Load("grafik1.png");
			}
			else if(x2<0){
				this->pictureBox1->Load("grafik2.png");
				this->x12->Text = "";
				
					if (resenje1 < resenje2) {
						this->rx1->Text = Convert::ToString(resenje1);
						this->rx2->Text = Convert::ToString(resenje2);
					}
					else {
						this->rx1->Text = Convert::ToString(resenje2);
						this->rx2->Text = Convert::ToString(resenje1);
					}
			}
			this->x1->Text = Convert::ToString(resenje1);
			this->x2->Text = Convert::ToString(resenje2);

		}
		else if (D == 0) {
			
			float resenje1 = float(-x + float(sqrt(pow(x, 2) - 4 * num*x2))) / float(2 * x2);
		//	float resenje2 = float(-x - float(sqrt(pow(x, 2) - 4 * num*x2))) / float(2 * x2);
			this->x12->Text= Convert::ToString(resenje1);
			this->rx1->Text = "";
			this->rx2->Text = "";
			if (x2 >= 0) {
				this->pictureBox1->Load("grafik3.png");
			}
			else {
				this->pictureBox1->Load("grafik4.png");
			}

			this->x1->Text = Convert::ToString(resenje1);
			this->x2->Text = Convert::ToString(resenje1);

		}else {
			this->rx1->Text = "";
			this->rx2->Text = "";
			this->x12->Text = "";
			if (x2 > 0) {
				this->pictureBox1->Load("grafik5.png");
			}
			else {
				this->pictureBox1->Load("grafik6.png");
			}
			this->x1->Text = "imaginary num ";
			this->x2->Text = "imaginary num ";
		}
	}
private: System::Void x1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void equation_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void x2_Click(System::Object^  sender, System::EventArgs^  e) {
}
		
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//upload
	OpenFileDialog^ op = gcnew OpenFileDialog();

	op->ShowDialog();
	op->Filter = "All supported graphics|*.jpg;*.jpeg;*.png|" +
		"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|" +
		"Portable Network Graphic (*.png)|*.png";
	op->Title = "Select picture";
	String^ str = op->FileName; //get the path of the selected file
	std::string filename = msclr::interop::marshal_as<std::string>(str);

	const size_t last_slash_idx = filename.find_last_of("\\/");
	if (std::string::npos != last_slash_idx)
	{
		filename.erase(0, last_slash_idx + 1);
	}
	//std::cout << filename;
	String^ str2 = gcnew String(filename.c_str());
	nameOfPicture->Text = str2;
}
	
	public: std::string getFilename() {
		if (nameOfPicture->Text == "")
			return "";
		std::string filename = msclr::interop::marshal_as<std::string>(nameOfPicture->Text);
		return filename;
	}

};

}
