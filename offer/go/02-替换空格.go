package offer

func Replace(str string) string {
	var s string = ""
	for i := 0; i < len(str); i++ {
		if str[i] == ' ' {
			s = s + "%20"
			continue
		}
		s = s + string(str[i])
	}
	return s
}
