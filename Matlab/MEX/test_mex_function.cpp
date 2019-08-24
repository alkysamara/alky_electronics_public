#include "mex.hpp"
#include "mexAdapter.hpp"

using namespace matlab::data;
using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function {
public:
    void operator()(ArgumentList outputs, ArgumentList inputs) {
        double a = inputs[0][0];
        double b = inputs[0][1];
		
		matlab::data::ArrayFactory factory;
		TypedArray<double> doubleArray = factory.createArray<double>({2, 1});
		
		doubleArray[0][0] = a + b;
		doubleArray[1][0] = a - b;
		
        outputs[0] = doubleArray;
    }
};