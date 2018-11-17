namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable[] ans;
            mutable res = true;		
            using (qs = Qubit[N]) {
                using (y = Qubit[1]) {
                    for (i in 0..N-1) {
                        H(qs[i]);
                    }
                    X(y[0]);
                    H(y[0]);
                    Uf(qs, y[0]);
                    for (i in 0..N-1) {
                        H(qs[i]);
                    
                    }
                    for (i in 0..N-1) {
                        let v = M(qs[i]);
                        if (v == One) {
                            set ans[i] = 1;
                        }
                        else {
                            set ans[i] = 0;
                        }
                    }
                    ResetAll(y);
                }
		    ResetAll(qs);
	        }
	    return ans;
		}
    }
}