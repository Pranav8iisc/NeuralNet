/*
Classes defining generic structures for neural networks. These classes may later be specialized to instantiate different types of networks.
*/
#include <list>

using namespace std;

// defines neuron class
template<class SignalDataType>
class Neuron
{
	public:
	
		unsigned int neuronId[2]; // assuming 2D neural networks
		SignalDataType *inputActivation;
		SignalDataType outputResponse;
		
		
		Neuron()
		{
			outputActivation = (class SignalDataType) 0;
		}		

		void computeActivation();
		

};

// defines the generic neural network
template<class WeightDataType, class SignalDataType>
class NeuralNetwork
{
	public:
	
		Neuron<SignalDataType>* inputLayer;
		Neuron<SignalDataType>** hiddenLayer; 
		Neuron<SignalDataType>* outputLayer;
			
		unsigned int nInputNeurons;
		unsigned int* nHiddenNeurons;
		unsigned int nOutputNeurons;
		unsigned int nHiddenLayers;

		WeightDataType** inputToHiddenConnectionWeights;
		WeightDataType*** hiddenToHiddenConnectionWeights;
		WeightDataType** hiddenToOutputConnectionWeights;

		void readTrainingData();
		void extractFeatures(); 
		void trainNetwork();
		void testNetwork();
};
