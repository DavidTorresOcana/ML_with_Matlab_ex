function [bestEpsilon bestF1] = selectThreshold(yval, pval)
%SELECTTHRESHOLD Find the best threshold (epsilon) to use for selecting
%outliers
%   [bestEpsilon bestF1] = SELECTTHRESHOLD(yval, pval) finds the best
%   threshold to use for selecting outliers based on the results from a
%   validation set (pval) and the ground truth (yval).
%

bestEpsilon = 0;
bestF1 = 0;
F1 = 0;

stepsize = (max(pval) - min(pval)) / 1000;

i=0;
for epsilon = min(pval):stepsize:max(pval)
    
    % ====================== YOUR CODE HERE ======================
    % Instructions: Compute the F1 score of choosing epsilon as the
    %               threshold and place the value in F1. The code at the
    %               end of the loop will compare the F1 score for this
    %               choice of epsilon and set it to be the best epsilon if
    %               it is better than the current choice of epsilon.
    %               
    % Note: You can use predictions = (pval < epsilon) to get a binary vector
    %       of 0's and 1's of the outlier predictions

    predictions = (pval < epsilon);
    
% %     tp+tn=sum(predictions==yval);   Ecs que nos dan los valores
% %     fp+fn=sum((predictions==yval)==0);
% %     sum(predictions==1)=tp+fp;
% %     sum(yval==1)=tp+fn;
    
    tp=sum((predictions==1).*(yval==1));
    fn=sum((predictions==0).*(yval==1));
    fp=sum((predictions==1).*(yval==0));
    prec=tp/(tp+fp);
    rec=tp/(tp+fn);
    
    F1=2*prec*rec/(prec+rec);
    i=i+1;
    data(i,:)=[epsilon,F1,prec,rec];

    % =============================================================

    if F1 > bestF1
       bestF1 = F1;
       bestEpsilon = epsilon;
       K=i;
    end
    
end
figure(1)
subplot(1,2,1)
plot(data(:,1),data(:,2));
hold on;
plot(bestEpsilon, bestF1, 'ro', 'LineWidth', 2, 'MarkerSize', 10);
xlabel('Epsilon');
ylabel('F1score');
title('F1 vs epsilon Se elige el mejor');
hold off;
subplot(1,2,2)
plot(data(:,3),data(:,4));
hold on;
plot(data(K,3),data(K,4), 'ro', 'LineWidth', 2, 'MarkerSize', 10);
xlabel('Recall');
ylabel('Precision');
title('Precision vs Recall Se elige el mejor');

pause;
hold off;


end
