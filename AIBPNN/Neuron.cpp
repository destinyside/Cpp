#include "Neuron.h"

Neuron::Neuron()
{
}

Neuron::Neuron(NodeType type):type(type)
{
}

void Neuron::setType(NodeType type)
{
	this->type = type;
}

double Neuron::getForwardInputValue()
{
	return this->forwardInputValue;
}

void Neuron::setForwardInputValue(double inputValue)
{
	this->forwardInputValue = inputValue;
	setForwardOutputValue(inputValue);
}

double Neuron::getForwardOutputValue()
{
	return this->forwardOutputValue;
}

double Neuron::getBackwardInputValue()
{
	return this->backwardInputValue;
}

void Neuron::setBackwardInputValue(double backwardInputValue)
{
	this->backwardInputValue = backwardInputValue;
	setBackwardOutputValue(backwardInputValue);
}

double Neuron::getBackwardOutputValue()
{
	return this->backwardOutputValue;
}

//private
void Neuron::setForwardOutputValue(double inputValue)
{
	this->forwardOutputValue = forwardSigmoid(inputValue);
}

//private
void Neuron::setBackwardOutputValue(double backwardInputValue)
{
	this->backwardOutputValue = backwardPropagate(backwardInputValue);
}

double Neuron::tanhS(double in)
{
	return (exp(in) - exp(-in)) / (exp(in) + exp(-in));
}

double Neuron::forwardSigmoid(double in)
{
	switch (type)
	{
	case Node_Input:
		return in;
	case Node_Hidden:
	case Node_Output:
		return tanhS(in);
	default:
		break;
	}
	return 0.0;
}


double Neuron::tanhSDerivative(double in)
{
	return ((1 - pow(forwardOutputValue, 2)) * in);
}

double Neuron::backwardPropagate(double in)
{
	switch (type)
	{
	case Node_Input:
		return in;
	case Node_Hidden:
	case Node_Output:
		return tanhSDerivative(in);
	default:
		break;
	}
	return 0.0;
}