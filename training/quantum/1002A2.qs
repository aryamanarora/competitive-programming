namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let l = Length(qs);
            for (i in 0 .. l - 1) {
                if (bits[i] == true) {
                    X(qs[i]);
                }
            }
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