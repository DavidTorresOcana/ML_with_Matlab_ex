%% Machine Learning Online Class
%  Exercise 5 | Regularized Linear Regression and Bias-Variance
%
%  Instructions
%  ------------
% 
%  This file contains code that helps you get started on the
%  exercise. You will need to complete the following functions:
%
%     linearRegCostFunction.m
%     learningCurve.m
%     validationCurve.m
%
%  For this exercise, you will not need to change any code in this file,
%  or any other files other than those mentioned above.
%

%% Initialization
clear ; close all; clc;

%% =========== Part 1: Loading and Visualizing Data =============
%  We start the exercise by first loading and visualizing the dataset. 
%  The following code will load the dataset into your environment and plot
%  the data.
%

% Load Training Data
fprintf('Loading and Visualizing Data ...\n')

% Load from ex5data1: 
% You will have X, y, Xval, yval, Xtest, ytest in your environment
load ('ex5data1.mat');

% m = Number of examples
m = size(X, 1);

% Plot training data
plot(X, y, 'rx', 'MarkerSize', 10, 'LineWidth', 1.5);
xlabel('Change in water level (x)');
ylabel('Water flowing out of the dam (y)');

fprintf('Program paused. Press enter to continue.\n');

% pause;
%% =========== Part 2: Regularized Linear Regression Cost =============
%  You should now implement the cost function for regularized linear 
%  regression. 
%

theta = [1 ; 1];
J = linearRegCostFunction([ones(m, 1) X], y, theta, 1);

fprintf(['Cost at theta = [1 ; 1]: %f '...
         '\n(this value should be about 303.993192)\n'], J);

fprintf('Program paused. Press enter to continue.\n');
%% =========== Part 3: Regularized Linear Regression Gradient =============
%  You should now implement the gradient for regularized linear 
%  regression.
%

theta = [1 ; 1];
[J, grad] = linearRegCostFunction([ones(m, 1) X], y, theta, 1);

fprintf(['Gradient at theta = [1 ; 1]:  [%f; %f] '...
         '\n(this value should be about [-15.303016; 598.250744])\n'], ...
         grad(1), grad(2));

fprintf('Program paused. Press enter to continue.\n');

%% =========== Part 4: Train Linear Regression =============
%  Once you have implemented the cost and gradient correctly, the
%  trainLinearReg function will use your cost function to train 
%  regularized linear regression.
% 
%  Write Up Note: The data is non-linear, so this will not give a great 
%                 fit.
%

%  Train linear regression with lambda = 0
lambda = 0;
[theta] = trainLinearReg([ones(m, 1) X], y, lambda);

%  Plot fit over the data
plot(X, y, 'rx', 'MarkerSize', 10, 'LineWidth', 1.5);
xlabel('Change in water level (x)');
ylabel('Water flowing out of the dam (y)');
hold on;
plot(X, [ones(m, 1),X]*theta, '--', 'LineWidth', 2)
hold off;

fprintf('Program paused. Press enter to continue.\n');
% pause;


%% =========== Part 5: Learning Curve for Linear Regression =============
%  Next, you should implement the learningCurve function. 
%
%  Write Up Note: Since the model is underfitting the data, we expect to
%                 see a graph with "high bias" -- slide 8 in ML-advice.pdf 
%

lambda = 0;  %% This time is without regularization
[error_train, error_val] = ...
    learningCurve([ones(m, 1) X], y, ...
                  [ones(size(Xval, 1), 1) Xval], yval, ...
                  lambda);

plot(1:m, error_train, 1:m, error_val);
title('Learning curve for linear regression')
legend('Train', 'Cross Validation')
xlabel('Number of training examples')
ylabel('Error')
axis([0 13 0 150])

fprintf('# Training Examples\tTrain Error\tCross Validation Error\n');
for i = 1:m
    fprintf('  \t%d\t\t%f\t%f\n', i, error_train(i), error_val(i));
end

fprintf('Program paused. Press enter to continue.\n');
% pause;

%% =========== Part 6: Feature Mapping for Polynomial Regression =============
%  One solution to this is to use polynomial regression. You should now
%  complete polyFeatures to map each example into its powers
%

p = 8;

% Map X onto Polynomial Features and Normalize
X_poly = polyFeatures(X, p);
[X_poly, mu, sigma] = featureNormalize(X_poly);  % Normalize
X_poly = [ones(m, 1), X_poly];                   % Add Ones

% Map X_poly_test and normalize (using mu and sigma)
X_poly_test = polyFeatures(Xtest, p);
X_poly_test = bsxfun(@minus, X_poly_test, mu);
X_poly_test = bsxfun(@rdivide, X_poly_test, sigma);
X_poly_test = [ones(size(X_poly_test, 1), 1), X_poly_test];         % Add Ones

% Map X_poly_val and normalize (using mu and sigma)
X_poly_val = polyFeatures(Xval, p);
X_poly_val = bsxfun(@minus, X_poly_val, mu);
X_poly_val = bsxfun(@rdivide, X_poly_val, sigma);
X_poly_val = [ones(size(X_poly_val, 1), 1), X_poly_val];           % Add Ones

fprintf('Normalized Training Example 1:\n');
fprintf('  %f  \n', X_poly(1, :));

fprintf('\nProgram paused. Press enter to continue.\n');




%% =========== Part 7: Learning Curve for Polynomial Regression =============
%  Now, you will get to experiment with polynomial regression with multiple
%  values of lambda. The code below runs polynomial regression with 
%  lambda = 0. You should try running the code with different values of
%  lambda to see how the fit and learning curve change.
%

lambda = 2;
[theta] = trainLinearReg(X_poly, y, lambda);

% Plot training data and fit
figure(1);
plot(X, y, 'rx', 'MarkerSize', 10, 'LineWidth', 1.5);
plotFit(min(X), max(X), mu, sigma, theta, p);
xlabel('Change in water level (x)');
ylabel('Water flowing out of the dam (y)');
title (sprintf('Polynomial Regression Fit (lambda = %f)', lambda));

figure(2);
[error_train, error_val] = ...
    learningCurve(X_poly, y, X_poly_val, yval, lambda);
plot(1:m, error_train, 1:m, error_val);

title(sprintf('Polynomial Regression Learning Curve (lambda = %f)', lambda));
xlabel('Number of training examples')
ylabel('Error')
axis([0 13 0 100])
legend('Train', 'Cross Validation')

fprintf('Polynomial Regression (lambda = %f)\n\n', lambda);
fprintf('# Training Examples\tTrain Error\tCross Validation Error\n');
for i = 1:m
    fprintf('  \t%d\t\t%f\t%f\n', i, error_train(i), error_val(i));
end

fprintf('Program paused. Press enter to continue.\n');
% pause;

%% =========== Part 8: Validation for Selecting Lambda =============
%  You will now implement validationCurve to test various values of 
%  lambda on a validation set. You will then use this to select the
%  "best" lambda value.
%

[lambda_vec, error_train, error_val] = ...
    validationCurve(X_poly, y, X_poly_val, yval);

close all;
plot(lambda_vec, error_train, lambda_vec, error_val);
legend('Train', 'Cross Validation');
xlabel('lambda');
ylabel('Error');

fprintf('lambda\t\tTrain Error\tValidation Error\n');
for i = 1:length(lambda_vec)
	fprintf(' %f\t%f\t%f\n', ...
            lambda_vec(i), error_train(i), error_val(i));
end

fprintf('Program paused. Press enter to continue.\n');
% pause;
%% =========== Part 9: Testing the result of the selected Lambda =============
%  Here we perform the test of the lambda choosen 
% The lambda choosed is lambda=3
lambda=3;
[theta] = trainLinearReg(X_poly, y, lambda);
[error_test,~]=linearRegCostFunction(X_poly_test, ytest, theta, 0);
fprintf('The lambda choose is %f \n and the error in test is %f\n',...
    lambda, error_test);

fprintf('Program paused. Press enter to continue.\n');
% pause;
%% =========== Part 10: Sweeping in lambda and polynomial order =============
% Here we make a sweep in the lambda an polynomial order until they reah
% the best solution

theta = [1 ; 1];
OO=10; % Higher order of the regresion polynomium
lambda_vec = [0 0.001 0.003 0.01 0.03 0.1 0.3 1 3 10]';
error_train=zeros(numel(lambda_vec),OO);
error_eval=zeros(numel(lambda_vec),OO);
for p=1:OO
    
    % Map X onto Polynomial Features and Normalize
     X_poly = polyFeatures(X, p);
    [X_poly, mu, sigma] = featureNormalize(X_poly);  % Normalize
    X_poly = [ones(m, 1), X_poly];                   % Add Ones

    % Map X_poly_test and normalize (using mu and sigma)
    X_poly_test = polyFeatures(Xtest, p);
    X_poly_test = bsxfun(@minus, X_poly_test, mu);
    X_poly_test = bsxfun(@rdivide, X_poly_test, sigma);
    X_poly_test = [ones(size(X_poly_test, 1), 1), X_poly_test];         % Add Ones

    % Map X_poly_val and normalize (using mu and sigma)
    X_poly_val = polyFeatures(Xval, p);
    X_poly_val = bsxfun(@minus, X_poly_val, mu);
    X_poly_val = bsxfun(@rdivide, X_poly_val, sigma);
    X_poly_val = [ones(size(X_poly_val, 1), 1), X_poly_val];           % Add Ones
    %---------------- Now we perform the error evaluation in fuction of
    %lambda-----------
    
    for j=1:numel(lambda_vec)
        [theta] = trainLinearReg(X_poly, y, lambda_vec(j));
        [error_train(j,p),~]=linearRegCostFunction(X_poly, y, theta, 0);
        [error_val(j,p),~]=linearRegCostFunction(X_poly_val, yval, theta, 0);
    end
    
end
figure(1);
surf(1:OO,lambda_vec,error_val);
xlabel('dregree');
ylabel('lambda');
zlabel('Error of validation');


fprintf('Program paused. Press enter to continue.\n');
pause;

%% =========== Part 11: Autochoosing the best parameters p and lambda =============
% Here we implement  an automatic algorithm for choosing the best degree
% and lambda parameter

theta = [1 ; 1];
OO=10; % Higher order of the regresion polynomium
lambda_vec = [0 0.001 0.003 0.01 0.03 0.1 0.3 1 3 10]';
error_train=zeros(numel(lambda_vec),OO);
error_eval=zeros(numel(lambda_vec),OO);
lambdaopt=zeros(OO,2);
enable=1;
p=0;
while p<=OO && enable==1
    p=p+1;
    % Map X onto Polynomial Features and Normalize
     X_poly = polyFeatures(X, p);
    [X_poly, mu, sigma] = featureNormalize(X_poly);  % Normalize
    X_poly = [ones(m, 1), X_poly];                   % Add Ones

    % Map X_poly_test and normalize (using mu and sigma)
    X_poly_test = polyFeatures(Xtest, p);
    X_poly_test = bsxfun(@minus, X_poly_test, mu);
    X_poly_test = bsxfun(@rdivide, X_poly_test, sigma);
    X_poly_test = [ones(size(X_poly_test, 1), 1), X_poly_test];         % Add Ones

    % Map X_poly_val and normalize (using mu and sigma)
    X_poly_val = polyFeatures(Xval, p);
    X_poly_val = bsxfun(@minus, X_poly_val, mu);
    X_poly_val = bsxfun(@rdivide, X_poly_val, sigma);
    X_poly_val = [ones(size(X_poly_val, 1), 1), X_poly_val];           % Add Ones
    %---------------- Now we perform the error evaluation until the optimum
    %lambda-----------------------------------
    j=0; 
    enable2=1;
    while j<=numel(lambda_vec) && enable2==1
        j=j+1;
        [theta] = trainLinearReg(X_poly, y, lambda_vec(j));
        [error_val(j,p),~]=linearRegCostFunction(X_poly_val, yval, theta, 0);
        if j>1 && error_val(j,p)>error_val(j-1,p)
            enable2=0;
            lambdaopt(p,:)=[j-1,error_val(j-1,p)];
        end
    end
    if lambdaopt(p,:)==0
        lambdaopt(p,:)=error_val(j,p);
    end
    
    if p>1 && lambdaopt(p,2)>lambdaopt(p-1,2)
        optimum=[p-1,lambdaopt(p-1,1),lambdaopt(p-1,2)];
        enable=0;
    end
    

end
figure(2);
surf(1:OO,lambda_vec,error_val);
xlabel('dregree');
ylabel('lambda');
zlabel('Error of validation');
hold on;
plot3([optimum(1)],[lambda_vec(optimum(2))],[optimum(3)],'ws--', 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');
    
    %perform the test 
    p=optimum(1);
    % Map X onto Polynomial Features and Normalize
     X_poly = polyFeatures(X, p);
    [X_poly, mu, sigma] = featureNormalize(X_poly);  % Normalize
    X_poly = [ones(m, 1), X_poly];                   % Add Ones

    % Map X_poly_test and normalize (using mu and sigma)
    X_poly_test = polyFeatures(Xtest, p);
    X_poly_test = bsxfun(@minus, X_poly_test, mu);
    X_poly_test = bsxfun(@rdivide, X_poly_test, sigma);
    X_poly_test = [ones(size(X_poly_test, 1), 1), X_poly_test];         % Add Ones

    % Map X_poly_val and normalize (using mu and sigma)
    X_poly_val = polyFeatures(Xval, p);
    X_poly_val = bsxfun(@minus, X_poly_val, mu);
    X_poly_val = bsxfun(@rdivide, X_poly_val, sigma);
    X_poly_val = [ones(size(X_poly_val, 1), 1), X_poly_val];           % Add Ones
    
    [theta] = trainLinearReg(X_poly, y, lambda_vec(optimum(2)));
    [error_test,~]=linearRegCostFunction(X_poly_test, ytest, theta, 0);
    fprintf('The lambda choose is %f \n and the error in test is %f\n',...
        lambda_vec(optimum(2)), error_test);

    fprintf('Program paused. Press enter to continue.\n');
    pause;
    
    


