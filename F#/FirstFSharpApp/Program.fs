// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.

let test x = x*2

test 4

[<EntryPoint>]
let main argv = 
    test 2
    0 // return an integer exit code
