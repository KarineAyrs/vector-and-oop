#pragma once
#include <iostream>
#include "geometr.h"
#include <string>
using namespace std;

class Interface {
private:
	Geometr g;
	typedef double (Geometr::*Double_s_param)(double);
	typedef double (Geometr::*Double_bez_param)();

	struct double_s_param{
		Double_s_param f=NULL;
		string descr="";
		string output="";
		string error="";
	};

	struct double_bez_param {
		Double_bez_param f = NULL;
		string descr = "";
		string output = "";
		string error = "";
	};
	struct mess_box {
		string descr = "";
	};


public:
	double_s_param d_s_p[2];
	double_bez_param d_b_p[3];
	mess_box messBox[4];

	void Interf_Hello() {
		cout << messBox[3].descr << endl;
	}
	void Interface_Work(int command) {
		double value;
		double par;
		switch (command) {
		case 0:
			cout << (messBox[0].descr) << endl;
			break;
		case 1:
			cout << d_b_p[0].descr << endl;
			value = (g.*d_b_p[0].f)();
			if (value == -1) {
				cout << d_b_p[0].error << endl;
			}
			else {
				cout << value<<endl;
				cout << d_b_p[0].output << endl;
			}
			break;
		case 2:
			cout << d_b_p[1].descr << endl;
			value = (g.*d_b_p[1].f)();
			if (value == -1) {
				cout << d_b_p[1].error << endl;
			}
			else {
				cout << value<<endl;
				cout << d_b_p[1].output << endl;
			}
			break;
		case 3:
			cout << messBox[1].descr << endl;
			break;
		case 4:
			cout << d_b_p[2].descr << endl;
			(g.*d_b_p[2].f)();
			break;
		case 5:
			cout << messBox[2].descr << endl;
			break;

		case 6:
			cout << d_s_p[0].descr << endl;
			cin >> par; 
			value = (g.*d_s_p[0].f)(par);
			if (value == -1) {
				cout << d_s_p[0].error << endl;
			}
			else {
				cout << d_s_p[0].output << endl;
			}
			break;
		case 7:
			cout << d_s_p[1].descr << endl;
			cin >> par;
			value = (g.*d_s_p[1].f)(par);
			if (value == -1) {
				cout << d_s_p[1].error << endl;
			}
			else {
				cout << d_s_p[1].output << endl;
			}
			break;
		default:
			cout << "wrong command. try again!" << endl;
		}
	}
};

