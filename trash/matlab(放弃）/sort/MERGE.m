function A=MERGE(A,p,q,r)
n1 = q-p+1;
n2 = r-q;
L = zeros(1,n1+1);
R = zeros(1,n2+1);
for i = 1:n1
    L(i) = A(p+i-1);
end
for j = 1:n2
    R(j) = A(q+j);
end
L(n1+1) = realmax;
R(n2+1) = realmax;
i = 1;j = 1;
for k = p:r
    if L(i) <= R(j)
        A(k) = L(i);
        i = i+1;
    else
        A(k) = R(j);
        j = j+1;
    end
end


    