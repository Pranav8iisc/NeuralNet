/*
Classes defining generic structures for neural networks. These classes may later be specialized to instantiate different types of networks.
*/
#include <list>

#define BACKPROP 1




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
template<class WeightDataType, class SignalDataType, class DatasetReaderType>
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


		DatasetReaderType* trainDataset;
		DatasetReaderType* testDataset;

		void readTrainingData();
		void extractFeatures(); 
		void trainNetwork();
		void testNetwork();
		
		void getNumberOfHiddenLayers();
		void getNumberOfOutputLayers();

	protected:
		unsigned int getNumberOfInputNeurons();
};



template<class WeightDataType, class SignalDataType, class DatasetReaderType>
void NeuralNetwork<WeightDataType, SignalDataType, DatasetReaderType>::readTrainingData()
{
	trainDataset.getDataset();
}

template<class WeightDataType, class SignalDataType, class DatasetReaderType>
void NeuralNetwork<WeightDataType, SignalDataType, DatasetReaderType>::extractFeatures()
{
	// ADDRESSES THE CASE WHEN FULL IMAGE IS GIVEN AS FEATURE
	nInputNeurons = trainDataset.sizeOfDimension[1]*trainDataset.sizeOfDimension[2];
}

template<class WeightDataType, class SignalDataType, class DatasetReaderType>
void NeuralNetwork<WeightDataType, SignalDataType, DatasetReaderType>::trainNetwork()
{
	
	unsigned int methodId;

	cout << "Please enter training method code:";
	cin >> methodId;
	
	switch(methodId):
	{
		case BACKPROP:
			while (terminationCriteria != true)
			{
				for ()
			}
	}
	
			
	return;
}




