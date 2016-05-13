%%
% load('largeScaleArrayRandom.mat');
% A = arrayRandom;
A=importdata('100w.txt');
%%
% A = [16,4,10,14,7,9,3,2,8,1];
% A = BUILD_MAX_HEAP(A); //test the BUILD_MAX_HEAP correct
tic
A = HEAPSORT(A);
toc
% Result: Elapsed time is 87.447640 seconds.
% just from this array A, we can consider that although heapsort &
% mergesort are both nlgn, mergesort costs 20s,and heapsort cost 90s.

% c++ vs MATLAB
%data 100w.txt
%MATLAB:85s   C++:0.37s
