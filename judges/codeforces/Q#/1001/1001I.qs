namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable resultArray = new Result[N];

            using (qubits = Qubit[N + 1]) {
                // last qubit is y-register
                X(qubits[N]);
                ApplyToEach(H, qubits);

                Uf(qubits);
                ApplyToEach(H, qubits[0..(N - 1)]); 

                // measure and reset all x-qubits
                for (idx in 0..(N - 1)) {
                    set resultArray[idx] = MResetZ(qubits[idx]);
                }
                // reset y
                Reset(qubits[N]);
            }
            return ForAll(IsResultZero, resultArray);
        }
    }
}