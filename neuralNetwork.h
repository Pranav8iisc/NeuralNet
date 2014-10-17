/*
Classes defining generic structures for neural networks. These classes may later be specialized to instantiate different types of networks.
*/
#include <list>

using namespace std;

// defines neuron class
template<class T>
class Neuron
{
	public:
	
		unsigned int neuronId;
		
		bool isInputLayerNeuron;
		
		if (isInputLayerNeuron)
			T inputActivation;
		
		T outputResponse;
		
		list<Neuron*> forwardNeighborNeurons;
		
		list<Neuron*> backwardNeighborNeurons;
		
		Neuron()
		{
			outputActivation = (class T) 0;
		}
		void computeActivation();	
};

// defines the generic neural network
class NeuralNetwork
{
	public:
	
		list<Neuron*> inputLayer;
		
		Neuron** hiddenLayer; // in general there may be arbitrary number of hidden layers
		
		list<Neuron*> outputLayer;
			
		unsigned int nInputNeurons;
		
		unsigned int* nHiddenNeurons;
		
		unsigned int nOutputNeurons;
		
		unsigned int nHiddenLayers;
};
