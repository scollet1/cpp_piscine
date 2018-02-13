#ifndef NN_HPP
# define NN_HPP

# include "Header.hpp"
# include "Layer.hpp"
# include "Neuron.hpp"

class NN {
private:
	Layer * _layers;
//	float * _errors;
	int _numLayers;
	int _numInputs;
	float **_memory;

public:
	NN(int numInputs, int numOutputs, int numLayers, int numNeurons) {
		int i;
		
		this->_layers = new Layer[numLayers];
		this->_numLayers = numLayers;
		this->_numInputs = numInputs;
		for (i = 0; i < numLayers; i++) {
			if (i == 0) {
				this->_layers[i] = Layer(numInputs);
			} else if (i == numLayers - 1) {
				this->_layers[i] = Layer(numOutputs);
			} else {
				this->_layers[i] = Layer(numNeurons);
			}
		}
		int io = numInputs + numOutputs;
		this->_memory = new float*[256];
		for (i = 0; i < 256; i++) {
			this->_memory[i] = new float[io];
		}
//		this->_errors = Layer(numOutputs);
	};~NN(){}

	void remember() {
	
	}


	float forwardPropogate(float *data, int snapshot) {
		for (int h = 0; h < this->_layers[0].get("NEURONS"); h++) {
			this->_memory[snapshot][h] = data[h];
			this->_layers[0].getNeuron(h).set("INPUT", data[h]);
		}

		for (int i = 0; i < this->_numLayers - 1; i++) {
			for (int j = 0; j < this->_layers[i + 1].get("NEURONS"); j++) {
				this->_layers[i + 1].
				getNeuron(j).
				set("INPUT", this->_layers[i].
				sumAll(j));
			}
			
		}

		float highest = 0;
		for (int o = 0;
			o < this->_layers[this->_numLayers - 1].get("NEURONS"); 
			o++)  {
			if (this->_layers[this->_numLayers - 1].
			getNeuron(o).get("OUTPUT") > highest) {
				this->_memory[snapshot][o + this->_numInputs] =
				this->_layers[this->_numLayers - 1].getNeuron(o).get("OUTPUT");
				highest = this->_layers[this->_numLayers - 1].
				getNeuron(o).get("OUTPUT");
			}
		}
		return highest;
	}
	
	float calculateReward(float health, float lives, float attackDamage) {
		return ((health * 10.0) + (lives * 5.0) + (attackDamage * 50.0)) / MAX_REWARD;
	}

	void backwardPropogate(float reward) {
		/*
		calculate expected inputs from reward
		*/
		for (int i = this->_numLayers; i > 0; i--) {
			for (int j = 0; j < this->_layers[i].get("NEURONS"); j++) {
				
			}
		}
		return;
	}

	float* calculateErrors(Layer layer) {
		float errors[layer.get("NEURONS")];

		return errors;
	} 

};

#endif
