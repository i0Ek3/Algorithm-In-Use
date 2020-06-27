package offer

func Find(tar int, num [][]int) bool {
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
