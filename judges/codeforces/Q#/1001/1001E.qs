namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let a = M(qs[0]);
            let b = M(qs[1]);
            if (a == One) {
                if (b == One) {
                    return 3;
                }
                else {
                    return 1;
                }
            }
            else {
                if (b == One) {
                    return 2;
                }
                else {
                    return 0;
                }
            }
        }
    }
}