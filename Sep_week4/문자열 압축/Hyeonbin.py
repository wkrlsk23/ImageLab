def solution(s):
    answer = []
    com_line = ""
    answer.append(len(s))

    for length in range(1, len(s) // + 1):
        line = ""
        num = 1
        for i in range(0, len(s), length):
            if s[i:i + length] == s[i + length:i + (2 * length)]:
                num += 1
            else:
                if num != 1:
                    line += str(num) + s[i:i + length]
                    com_line += line
                    num = 1
                    line = ""
                else:
                    com_line += s[i:i + length]

        if len(com_line) != len(s):
            answer.append(len(com_line))
            print(com_line)
        com_line = ""

    return min(answer)