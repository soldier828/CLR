function A=mergeSort(A,p,r)
if p < r
    q = round((p+r)/2-0.5);
    A=mergeSort(A,p,q);
    A=mergeSort(A,q+1,r);
    A=MERGE(A,p,q,r);
end