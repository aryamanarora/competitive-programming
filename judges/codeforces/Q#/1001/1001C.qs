namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {   
            let l = Length(qs);
            if (l == 1) {
                H(qs[0]);
            }
            if (l == 2) {
                H(qs[0]);
                CNOT(qs[0], qs[1]);
            }
            if (l > 2) {
                H(qs[0]);
                for (i in 0 .. l - 2) {
                    CNOT(qs[i], qs[i + 1]);
                }
            }
        }
    }
}