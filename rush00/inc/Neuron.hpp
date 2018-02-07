#ifndef NEURON_HPP
# define NEURON_HPP

# include "Header.hpp"

class Neuron {
private:
	float _input;
	float _output;
	float * _weights;
	float _numWeights;
	float _bias;

public:
	Neuron(int connections) {
		this._numWeights = connections;
		this._bias = RNG(-1, 1);
		this._weights = new float[connections];
		for (int i = 0; i < connections; i++) {
			this._weights[i] = RNG(-1, 1);
		}
	}~Neuron(){}

	public float RNG(float Min, float Max)
	{
		return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	}

	public float activate(float input) {
		this._output = input;
	}
	
	public float derive(float input) {
		return input * (1 - input);
	}

	public float getWeight(int index) {
		return this._weights[index];
	}

	public float get(std::string opt) {
		if (opt.equals("INPUT")) {
			return this._input;
		} else if (opt.equals("OUPUT") {
			return this._output;
		} else if (opt.equals("WEIGHTS") {
			return this._numWeights;
		} else if (opt.equals("BIAS") {
			return this._bias;
		} else return null;
	}

	public void set(std::string opt, float value) {
		if (opt.equals("INPUT") {
			this._input = value;
		} else if (opt.equals("OUTPUT") {
			this._output = value;
		} else;
	}
}

#endif
