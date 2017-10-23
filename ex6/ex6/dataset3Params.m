function [C, sigma] = dataset3Params(X, y, Xval, yval)
%EX6PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = EX6PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.

C_vec=[0.01,0.03,0.1,0.3,1,3,10,30];
sigma_vec=C_vec;
J_val=zeros(size(C_vec,2),size(C_vec,2));
for i=1:size(C_vec,2)
    for j=1:size(C_vec,2)
        model= svmTrain(X, y, C_vec(i), @(x1, x2) gaussianKernel(x1, x2, sigma_vec(j)));
        pred = svmPredict(model, Xval);
        J_val(i,j)=mean(double(pred~=yval));
    end
end

surf(C_vec,sigma_vec,J_val);
xlabel('C');
ylabel('sigma');
zlabel('Validation error');
pause;

    [~,I]=min(min(J_val,[],1));
    sigma=sigma_vec(I);
    [~,I]=min(min(J_val,[],2));
    C=C_vec(I);
    
% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%







% =========================================================================

end
