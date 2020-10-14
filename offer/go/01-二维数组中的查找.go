package offer

func Find1(tar int, num [][]int) bool {
	if len(num) == 0 {
		return false
	}

	n := len(num)
	m := len(num[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if num[i][j] == tar {
				return true
			}
		}
	}
	return false
}

func Find2(tar int, num [][]int) bool {
	n := len(num)
	m := len(num[0])

	for i, j := 0, m-1; i < n && m > 0; {
		if num[i][j] == tar {
			return true
		} else if num[i][j] > tar {
			m--
		} else {
			n++
		}
	}
	return false
}
