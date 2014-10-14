/*
This class implements multi-layer perceptron network with linear activation function based neurons.
*/

class LinearNeuron : public Neuron
{
    void computeActivation()
    {
        for (list<neuron*>::iter nIter = backwardNeighborNeurons.begin(); nIter != backwardNeighborNeurons.end(); nIter++)
            {
                inputActivation += nIter.outputResponse * nIter.weight[][];
                
            }
    }
};





class linearNeuronPerceptronNetwork : public NeuralNetwork
{
    
    void computeActivation()
    {
        
    }
};
