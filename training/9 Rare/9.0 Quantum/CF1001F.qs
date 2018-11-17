namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable ans = 0;
            for (i in 0 .. Length(qs) - 1) {
                let a = M(qs[i]);
                if (a == One && bits0[i] == false) {
                    set ans = 1;
                }
                if (a == Zero && bits0[i] == true) {
                    set ans = 1;
                }
            }
            return ans;
        }
    }
}