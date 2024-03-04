def bagOfTokensScore(tokens: list[int], power: int) -> int:
        tokens.sort()
        i, j = 0, len(tokens) - 1
        score, maxScore = 0, 0

        while i <= j:
            if power >= tokens[i]:
                power = power - tokens[i]
                score += 1
                i += 1
            elif score > 0:
                score -= 1
                power += tokens[j]
                j -= 1
            else:
                return maxScore
            maxScore = max(score, maxScore)
        
        return maxScore

tokens = [200,100]
power = 150

bagOfTokensScore(tokens, power)