%% Machine Learning Online Class
%  Exercise 1: Linear regression with multiple variables
%
%  Instructions
%  ------------
% 
%  This file contains code that helps you get started on the
%  linear regression exercise. 
%
%  You will need to complete the following functions in this 
%  exericse:
%
%     warmUpExercise.m
%     plotData.m
%     gradientDescent.m
%     computeCost.m
%     gradientDescentMulti.m
%     computeCostMulti.m
%     featureNormalize.m
%     normalEqn.m
%
%  For this part of the exercise, you will need to change some
%  parts of the code below for various experiments (e.g., changing
%  learning rates).
%

%% Initialization

%% ================ Part 1: Feature Normalization ================

%% Clear and Close Figures
clear ; close all; clc
global lambda
fprintf('Loading data ...\n');

%% Load Data
data = load('ex1data1.txt');
X = data(:, 1);
y = data(:, 2);
m = length(y);
grado=2;
lambda=2000;
X=[X,zeros(size(X,1),grado-1)];
for j=1:grado
    X(:,j)=X(:,1).^j;
end
% Print out some data points
fprintf('First 10 examples from the dataset: \n');
fprintf(' x = [%.0f %.0f], y = %.0f \n', [X(1:10,:) y(1:10,:)]');

fprintf('Program paused. Press enter to continue.\n');


% Scale features and set them to zero mean
fprintf('Normalizing Features ...\n');

[X,mu,sigma] = featureNormalize(X);

% Add intercept term to X
X = [ones(m, 1), X]


%% ================ Part 2: Gradient Descent ================

% ====================== YOUR CODE HERE ======================
% Instructions: We have provided you with the following starter
%               code that runs gradient descent with a particular
%               learning rate (alpha). 
%
%               Your task is to first make sure that your functions - 
%               computeCost and gradientDescent already work with 
%               this starter code and support multiple variables.
%
%               After that, try running gradient descent with 
%               different values of alpha and see which one gives
%               you the best result.
%
%               Finally, you should complete the code at the end
%               to predict the price of a 1650 sq-ft, 3 br house.
%
% Hint: By using the 'hold on' command, you can plot multiple
%       graphs on the same figure.
%
% Hint: At prediction, make sure you do the same feature normalization.
%

% Tambien hacemos un barrido en alpha para ver la evolucion de las
% iteraciones
alpha(1) = 0.1;
num_iters = 400;
k=1;
out=0;
% % % while k<10 && out==0;
    fprintf('Running gradient descent ...\n');

    % Init Theta and Run Gradient Descent 
    theta = zeros(size(X,2), 1);
    [theta, J_history,num_itersDone(k),fail] = gradientDescentMulti(X, y, theta, alpha(k), num_iters);
    close all;
    
    
    % Plot the convergence graph
    figure;
    plot(1:numel(J_history), J_history, '-b', 'LineWidth', 2);
    xlabel('Number of iterations ');
    ylabel('Cost J');

    % Display gradient descent's result
    fprintf('Theta computed from gradient descent with alpha %f: \n',alpha(k));
    fprintf(' %f \n', theta);
    fprintf('\n');
    
% % %     alpha(k+1)=alpha(k)*1.5;
% % %     k=k+1;
% % % end

% % % close all;
% % % plot(alpha(1:end-1),num_itersDone);
% % % title(' numero de iteraciones necesarias para converegecia Vs. alpha');
% % % pause;
% Plot the linear fit
close all;
plotData(X(:,2),y);
hold on; % keep previous plot visible
x2=transpose(  min(X(:,2)):0.5:max(X(:,2)) );
x2=[x2,zeros(size(x2,1),size(X,2)-2)];
for j=1:size(x2,2)
    x2(:,j)=x2(:,1).^j;
end
x2=[ones(size(x2(:,1))),x2];
plot(x2(:,2), x2*theta, '-')
legend('Training data', 'Linear regression')
hold off
