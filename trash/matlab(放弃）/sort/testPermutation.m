
% array 5w
% num=1000000;
% randomArray(num);
load('largeScaleArrayRandom.mat');
insertionSort_arrayRandom = arrayRandom;
mergeSort_arrayRandom = arrayRandom;

%% insertionSort
tic
insertionSortArray=insertionSort(insertionSort_arrayRandom);
toc

%%
tic
sortedArray=mergeSort(mergeSort_arrayRandom,1,size(mergeSort_arrayRandom,2));
toc

%%
%Answer:insert:      merge:Elapsed time is 17.340721 seconds.