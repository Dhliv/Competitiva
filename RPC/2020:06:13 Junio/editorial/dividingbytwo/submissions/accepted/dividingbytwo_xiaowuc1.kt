private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var l = readInts()
    var ret = 0
    var a = l[0]
    var b = l[1]
    while (a != b) {
        if (a < b) {
            ret += b-a
            break
        }
        ret++
        if (a%2 == 0) {
            a /= 2
        } else {
            a++
        }
    }
    println(ret)
}

