function A = HEAPSORT(A)
A = BUILD_MAX_HEAP(A);
A_length = length(A);
A_heapsize = A_length;
for i = A_length:-1:2
    temp = A(i);
    A(i) = A(1);
    A(1) = temp;
    A_heapsize = A_heapsize - 1;
    A = MAX_HEAPIFY(A, 1, A_heapsize);
end