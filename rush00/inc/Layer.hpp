#ifndef LAYER_HPP
# define LAYER_HPP

# include "Header.hpp"

class Layer {
private:
	Nueron * neurons;
	float _numNeurons;

public:
	Layer(int neurons) {
		this._numNeurons = neurons;
		neurons = new Neuron(neurons)[neurons];
//		for (int i = 0; i < neurons; i++) {
//			neuron
//		} 
	}~Layer(){}

	public float sumAll(int index) {
		float result = 0;
		for (int i = 0; i < this._numNeurons(); i++) {
			result += this._neurons[i].get("OUTPUT") * this._neurons[i].getWeight(index);
		}
		return result;
	}

	public Neuron getNeuron(int index) {
		return this._neurons[index];
	}

	public float get(std::string opt) {
		if (opt.equals("NEURONS")) {
			return this._numNeurons;
		} else return null;
	}
}

#endif
