typedef eigenMatrix Matrix;

class NeuralNetworks
{

	protected:
	
		
		unsigned int nInputLayerNerurons;
		unsigned int nHiddenLayers;		
		unsigned int *nHiddenLayerNeurons;
		

		Matrix *inputToHiddenLayerWeights;
		Matrix *hiddenToOutputLayerWeights;

		Matrix *hiddenLayerBias;
		Matrix *outputLayerBias;

		
	public:	
		void trainNetwork();
		void testNetwork();

};


void NeuralNetworks::initialize()
{
	 // initialize with Gaussian probaility distribution

}


void NeuralNetworks::computeHiddenUnitResponse(Matrix *s, Matrix *h)
{	
	Matrix x = new Matrix(nHiddenLayerNeurons[0]);

	x = inputToHiddenLayerWeights * s + hiddenLayerBias;		
	h = sigmoid(x);	

}


void NeuralNetworks::computeOutputUnitResponse(Matrix *h, Matrix *r)
{
	Matrix x = new Matrix(nOutputLayerNeurons);

	x = hiddenToOutputLayerWeights * h + outputLayerBias;
	r = sigmoid(x);
}


void NeuralNetworks::computeOutputError(Matrix * o, Matrix *r, Matrix *error)
{
	errorOutput = abs(o - r);	
	
}


void NeuralNetworks::backpropogateError()
{
	errorHidden = transpose(hiddenToOutputLayerWeight) * D * errorOutput;	
}

void updateWeightsAndBiases()
{


}

void NeuralNetworks::trainNetwork()
{


	
	cout << "\nPlease enter number of input layer neurons:";
	cin >> nInputLayerNeurons;

	cout << "\nPlease enter number of hidden layers:";
	cin >> nHiddenLayers;


	IdxDatasetReader trainingInputDataset;
	IdxDatasetReader trainingOutputDataset;

	trainingInputDataset.getDataset("trainImages.idx");
	trainingOutputDataset.getDataset("trainLabels.idx");

	// convert training data to eigen matrix form:
	
	Matrix *s = convertCharToEigenMat(trainingInputDataset);
	Matrix *o = convertCharToEigenMat(trainingOutputDataset);


	nHiddenLayerNeurons = new unsigned int[nHiddenLayers];	

	for (unsigned int n = 0; n < nHiddenLayers; n++)
	{
		cout << "\nPlease enter number of hidden layer neurons for layer-%:" << n;
		cin >> nHiddenLayerNeurons;		
	}
	


	if (nHiddenLayers == 1) // single layer networks
	{

		Matrix *h = new Matrix(nHiddenLayerNeurons[0]);

		inputToHiddenLayerWeights = new Matrix(nHiddenLayerNeurons[0], nInputLayerNeurons);
		hiddenToOutputLayerWeights = new Matrix(nOutputLayerNeurons, nHiddenLayerNeuwons[0]);
		

		hiddenLayerBias = new Matrix(nHiddenLayerNeurons[0]);
		outputLayerBias = new Matrix(nOutputLayerNeurons[0]);


		initialize(inputToHiddenLayerWeights);
		initialize(hiddenToOutputLayerWeights);		

		initialize(hiddenLayerBias);		 
		initialize(outputLayerBias);

		
		bool terminationCondition = false;
		float averageOutputError = 0.0;		

		while (terminationCondition != true)
		{
			computeHiddenLayerResponse(s, h);
			computeOutputLayerResponse(h, r);			
			computeOutputError(o, r, averageOutputError);
			backpropogateError();
			updateWeightsAndBiases();
		}
	}	

	else
	{
		cout << "Work in progress...these cases are not addressed currently..."
	}



}


void testNetwork()
{

}
