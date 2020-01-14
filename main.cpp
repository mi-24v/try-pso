#include <iostream>
#include <armadillo>
#include <optim.hpp>
 
double table_fn(const arma::vec& vals_inp, arma::vec* grad_out, void* opt_data)
{
    const double x = vals_inp(0);
    const double y = vals_inp(1);
    const double pi = arma::datum::pi;
 
    double obj_val = - std::abs( std::sin(x)*std::cos(y)*std::exp( std::abs(1.0 - std::sqrt(x*x + y*y)/pi) ) );
    //
    return obj_val;
}
 
double bukin_fn(const arma::vec& vals_inp, arma::vec* grad_out, void* opt_data)
{
    const double x = vals_inp(0);
    const double y = vals_inp(1);
 
    double obj_val = 100*std::sqrt(std::abs(y - 0.01*x*x)) + 0.01*std::abs(x + 10);
    //
    return obj_val;
}
 
int main()
{
    //
    // Table function
 
    optim::algo_settings_t settings_1;
 
    settings_1.pso_center_particle = false;
    // settings_1.pso_par_bounds = true;
 
    arma::vec x_1 = arma::zeros(2,1);
 
    settings_1.pso_initial_lb = arma::zeros(2,1) - 10.0;
    settings_1.pso_initial_ub = arma::zeros(2,1) + 10.0;
 
    settings_1.pso_n_pop = 5000;
    settings_1.pso_n_gen = 4000;
 
    bool success_1 = optim::pso(x_1,table_fn,nullptr,settings_1);
 
    if (success_1) {
        std::cout << "pso: Table test completed successfully." << std::endl;
    } else {
        std::cout << "pso: Table test completed unsuccessfully." << std::endl;
    }
 
    arma::cout << "pso: solution to Table test:\n" << x_1 << arma::endl;
 
    //
    // Bukin function no. 6
 
    arma::vec x_2 = arma::ones(2,1) + 1.0; // initial values: (2,2)
 
    bool success_2 = optim::de(x_2,bukin_fn,nullptr);
 
    if (success_2) {
        std::cout << "de: Bukin test completed successfully." << std::endl;
    } else {
        std::cout << "de: Bukin test completed unsuccessfully." << std::endl;
    }
 
    arma::cout << "de: solution to Bukin test:\n" << x_2 << arma::endl;
 
    return 0;
}