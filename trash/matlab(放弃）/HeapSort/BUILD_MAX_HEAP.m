function A = BUILD_MAX_HEAP(A)
length_A = length(A);
A_heapsize = length_A;
start = round(length_A / 2 -0.5);
for i = start:-1:1
    A = MAX_HEAPIFY(A, i, A_heapsize);
end