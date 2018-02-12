#ifndef NN_HPP
# define NN_HPP

# include "Header.hpp"
# include "Layer.hpp"
# include "Neuron.hpp"

class NN {
private:
	Layer * _layers;
	Layer * _errors;
	int _numLayers;

public:
	NN(int inputs, int outputs, int layers, int neurons) {
		this->_layers = new Layer()[layers];
		this._num_layers = layers;
		for (int i = 0; i < layers; i++) {
			if (i == 0) { 
				this->_layers[i] = new Layer(inputs);
			} else if (i == layers - 1) {
				this->_layers[i] = new Layer(outputs);
			} else {
				this->_layers[i] = new Layer(neurons);
			}
		}
		this->_errors = new Layer(outputs);
	}~NN(){}


	public Layer * forwardPropogate() {
		
		for (int i = 0; i < this->_numLayers - 1; i++) {
			for (int j = 0; j < this->_layers[i + 1].getNeuron(); j++) {
				this->_layers[i + 1].getNeuron(j).set("INPUT", this->_layers[i].sumAll(j));
			}
			
		}
		float highest = 0;
		for (int o = 0;
			o < this->_layers[this->_numLayers - 1].get("NEURONS"); 
			o++)  {
			if (this._layers[this._numLayers - 1].getNeuron(o).get("OUTPUT") > 0) {
				highest = this._layers[this._numLayers - 1].getNeuron(o).get("OUTPUT");
			}
		}
		return highest;
	}
	
	public void backwardPropogate(Game game) {

	}

	public Layer calculateErrors() {
		
	} 

};

#endif
