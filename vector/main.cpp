#include <iostream>
#include "interface.h"
#include "geometr.h"
#include <string>
#include <time.h>
#include "intrfLanguage.h"
using namespace std;

int main()
{
	int command;

	Interface intrf;

	intrf.messBox[0].descr = type_of_figures_q; 
	intrf.messBox[1].descr = if_want_ex_q; 
	intrf.messBox[2].descr =do_want_per_q; 
	intrf.messBox[3].descr = welcome_message; 

	intrf.d_b_p[0].f = &(Geometr::area); 
	intrf.d_b_p[0].descr = this_area;
	intrf.d_b_p[0].output =do_want_new_fig;
	intrf.d_b_p[0].error = no_fig_error;

	intrf.d_b_p[1].f = &(Geometr::perimetr); 
	intrf.d_b_p[1].descr = this_per;
	intrf.d_b_p[1].output = do_want_new_fig;
	intrf.d_b_p[1].error = no_fig_error;
	
	intrf.d_b_p[2].f = &(Geometr::mess_box4); 
	intrf.d_b_p[2].descr = good_bye;

	intrf.d_s_p[0].f = &(Geometr::inp_sqr);
	intrf.d_s_p[0].descr = inp_param;
	intrf.d_s_p[0].output = fig_success_area;
	intrf.d_s_p[0].error = wrong_param;
	
	intrf.d_s_p[1].f = &(Geometr::inp_cr);
	intrf.d_s_p[1].descr = inp_param;
	intrf.d_s_p[1].output =fig_success_area;
	intrf.d_s_p[1].error = wrong_param;
	

	intrf.Interf_Hello();

	while (true) {
		cin >> command;
		intrf.Interface_Work(command);
		command = -1;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
		

	/*clock_t start = clock();
	Square *sqr;
	for (int i = 0; i < 1e7; i++) {
		cout << i<<" ";
	sqr = new Square(5);
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "moy: " << seconds << endl;

	start = clock();
	for (int i = 0; i < 1e7; i++)
	{
		cout << i << " ";
	sqr = ::new Square(5);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "default: " << seconds << endl;
*/


	return 0;
}