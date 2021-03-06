%% Machine Learning Online Class - Exercise 4 Neural Network Learning

%  Instructions
%  ------------
% 
%  This file contains code that helps you get started on the
%  linear exercise. You will need to complete the following functions 
%  in this exericse:
%
%     sigmoidGradient.m
%     randInitializeWeights.m
%     nnCostFunction.m
%
%  For this exercise, you will not need to change any code in this file,
%  or any other files other than those mentioned above.
%

%% Initialization
clear all; close all; clc;

%% Setup the parameters you will use for this exercise
                            % 2 hidden layers both with the same units
input_layer_size  = 2;  % 
hidden_layer_size = 50;   % 25 hidden units
num_labels = 1;          % 1 label Solo queremos el ajuste a un numero
%% =========== Part 1: Loading and Visualizing Data =============
%  We start the exercise by first loading and visualizing the dataset. 
%  You will be working with a dataset that contains handwritten digits.
%

% Load Training Data
fprintf('Loading and Visualizing Data ...\n')

data = load('ex1data2.txt');
X = data(:, 1:2);
y = data(:, 3);
m = length(y);

% Randomly select 100 data points to display
sel = randperm(size(X, 1));
sel = sel(1:0.8*m);
scatter(X(sel, 2),X(sel, 1));

fprintf('Normalizing Features ...\n');

[X,mu,sigma] = featureNormalize(X);
fprintf('Program paused. Press enter to continue.\n');

%% ================ Part 2: Setting Parameters ================
% In this part of the exercise, we load some pre-initialized 
% neural network parameters.

fprintf('\nLoading Saved Neural Network Parameters ...\n')


% Theta1 has size 25 x 401
% Theta2 has size 25 x 26
% Theta3 has size 1 x 26
% Unroll parameters 
epsilon=0.01;

Theta1=rand(hidden_layer_size,input_layer_size+1)*2*epsilon-epsilon;
Theta2=rand(hidden_layer_size,hidden_layer_size+1)*2*epsilon-epsilon;
Theta3=rand(num_labels,hidden_layer_size+1)*2*epsilon-epsilon;

nn_params = [Theta1(:) ; Theta2(:); Theta3(:)];

%% ================ Part 3: Compute Cost (Feedforward) ================
%  To the neural network, you should first start by implementing the
%  feedforward part of the neural network that returns the cost only. You
%  should complete the code in nnCostFunction.m to return cost. After
%  implementing the feedforward to compute the cost, you can verify that
%  your implementation is correct by verifying that you get the same cost
%  as us for the fixed debugging parameters.
%
%  We suggest implementing the feedforward cost *without* regularization
%  first so that it will be easier for you to debug. Later, in part 4, you
%  will get to implement the regularized cost.
%
fprintf('\nFeedforward Using Neural Network ...\n')

% Weight regularization parameter (we set this to 0 here).
lambda = 0;

J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
                   num_labels, X, y, lambda);


fprintf('\nProgram paused. Press enter to continue.\n');

%% =============== Part 4: Implement Regularization ===============
%  Once your cost function implementation is correct, you should now
%  continue to implement the regularization with the cost.
%

fprintf('\nChecking Cost Function (w/ Regularization) ... \n')

% Weight regularization parameter (we set this to 1 here).
lambda = 1;

J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
                   num_labels, X, y, lambda);


fprintf('Program paused. Press enter to continue.\n');


%% ================ Part 6: Initializing Pameters ================
%  In this part of the exercise, you will be starting to implment a two
%  layer neural network that classifies digits. You will start by
%  implementing a function to initialize the weights of the neural network
%  (randInitializeWeights.m)

fprintf('\nInitializing Neural Network Parameters ...\n')

initial_Theta1 = randInitializeWeights(input_layer_size, hidden_layer_size);
% initial_Theta12 = randInitializeWeights2(Theta1);  % Es igual que randInitializeWeights
initial_Theta2 = randInitializeWeights(hidden_layer_size, hidden_layer_size);
initial_Theta3 = randInitializeWeights(hidden_layer_size, num_labels);

% Unroll parameters
initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:);initial_Theta3(:)];


%% =============== Part 7: Implement Backpropagation ===============
%  Once your cost matches up with ours, you should proceed to implement the
%  backpropagation algorithm for the neural network. You should add to the
%  code you've written in nnCostFunction.m to return the partial
%  derivatives of the parameters.
%
fprintf('\nChecking Backpropagation... \n');
lambda=0;
%  Check gradients by running checkNNGradients
checkNNGradients;

fprintf('\nProgram paused. Press enter to continue.\n');



%% =============== Part 8: Implement Regularization ===============
%  Once your backpropagation implementation is correct, you should now
%  continue to implement the regularization with the cost and gradient.
%

fprintf('\n Checking Backpropagation (w/ Regularization) ... \n')

%  Check gradients by running checkNNGradients
lambda = 3;
checkNNGradients(lambda);


fprintf('Program paused. Press enter to continue.\n');



%% =================== Part 8: Training NN ===================
%  You have now implemented all the code necessary to train a neural 
%  network. To train your neural network, we will now use "fmincg", which
%  is a function which works similarly to "fminunc". Recall that these
%  advanced optimizers are able to train our cost functions efficiently as
%  long as we provide them with the gradient computations.
%
fprintf('\nTraining Neural Network... \n')

%  After you have completed the assignment, change the MaxIter to a larger
%  value to see how more training helps.
options = optimset('MaxIter', 200);

%  You should also try different values of lambda
lambda = 0.5

% Create "short hand" for the cost function to be minimized
costFunction = @(p) nnCostFunction(p, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, X, y, lambda);

% Now, costFunction is a function that takes in only one argument (the
% neural network parameters)
[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);

% Obtain Theta1 and Theta2 back from nn_params
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):( (hidden_layer_size * (input_layer_size + 1))) + hidden_layer_size*(hidden_layer_size+1)  ), ...
                 hidden_layer_size, (hidden_layer_size + 1));

Theta3 = reshape(nn_params(( 1 + (hidden_layer_size * (input_layer_size + 1)))+hidden_layer_size*(hidden_layer_size+1):end  ), ...
                 num_labels, (hidden_layer_size + 1));

fprintf('Program paused. Press enter to continue.\n');



%% ================= Part 9: Visualize Weights =================
%  You can now "visualize" what the neural network is learning by 
%  displaying the hidden units to see what features they are capturing in 
%  the data.
% % % 
% % % fprintf('\nVisualizing Neural Network... \n')
% % % figure(1)
% % % displayData(Theta1(:, 2:end));
% % % figure(2)
% % % displayData(Theta2(:, 2:end));
% % % fprintf('\nProgram paused. Press enter to continue.\n');


% Predict an example
X1=[1,([1650,3]-mu)./sigma];
% Forward
        a1=X1';
        z2=Theta1*a1;
        a2=[1 ;  (z2)];
        z3=Theta2*a2;
        a3=[1 ;  (z3)];
        z4=Theta3*a3;
        a4=z4;
        price=a4;

fprintf(['Predicted price of a 1650 sq-ft, 3 br house ' ...
         '(using gradient descent):\n $%f\n'], price);

%% ================= Part 10: Implement Predict =================
%  After training the neural network, we would like to use it to predict
%  the labels. You will now implement the "predict" function to use the
%  neural network to predict the labels of the training set. This lets
%  you compute the training set accuracy.

pred = predict(Theta1, Theta2, Theta3, X);

%  YA NO VAMOS A USAR MAS X VOLVEMOS A LOS VALORES ORIGINALES

% X=bsxfun(@times, bsxfun(@plus,X , mu), sigma);
X= data(:, 1:2);
scatter3(X(:,1),X(:,2),y)
hold on
% [X2x,X2y] = meshgrid( linspace(min(X(:,1)),max(X(:,1)),10), linspace(min(X(:,2)),max(X(:,2)),10));                                
% 
% [X2ynorm,mu2,sigma2] = featureNormalize(X2y);
% [X2xnorm,mu2,sigma2] = featureNormalize(X2x);
% for i=1:10
%     for j=1:10
%         V=[X2xnorm(i,j),X2ynorm(i,j)]
%         P(i,j)=predict(Theta1, Theta2,V);
%     end
% end
% 
% surf(X2x,X2y,P)

scatter3(X(:,1),X(:,2),pred,'r')
scatter3(1650,3,price,'g')
hold off
fprintf('\n Error medio de la prediccion: %f \n', mean(abs(double( (pred - y)./y ))) * 100);


