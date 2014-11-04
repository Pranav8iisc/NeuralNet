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
	
		unsigned int neuronId[2]; // assuming 2D neural networks
		T *inputActivation;
		T outputResponse;
		//Neuron* forwardNeighborNeurons;
		//Neuron* backwardNeighborNeurons;
		
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
	
		Neuron* inputLayer;
		Neuron** hiddenLayer; // in general there may be arbitrary number of hidden layers
		Neuron* outputLayer;
			
		unsigned int nInputNeurons;
		unsigned int* nHiddenNeurons;
		unsigned int nOutputNeurons;
		unsigned int nHiddenLayers;

		T inputToHiddenConnectionWeights;
		T hiddenToHiddenConnectionWeights;
		T hiddenToOutputConnectionWeights;

		void readTrainingData();
		void extractFeatures(); 
		void trainNetwork();
		void testNetwork();
};
