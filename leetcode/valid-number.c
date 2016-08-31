/**
 * 有限状态机 fsm
 */
enum NumState {
	PREFIX_SPACE = 0,
	SIGN_PART,
	INT_PART,
	NO_INT_DOT,
	INT_DOT,
	DECI_PART,
	EXP_SYM,
	EXP_SIGN,
	EXP_INT,
	SUFFIX_SPACE,
	ERROR,
};
enum NumState prefix_space_fsm(char c) {
	enum NumState state = ERROR;
	if (c == ' ') state = PREFIX_SPACE;
	else if (c == '+' || c == '-') state = SIGN_PART;
	else if (c >= '0' && c <= '9') state = INT_PART;
	else if (c == '.') state = NO_INT_DOT;
	else state = ERROR;

	return state;
}
enum NumState sign_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = INT_PART;
	else if (c == '.') state = NO_INT_DOT;
	else state = ERROR;

	return state;
}
enum NumState int_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = INT_PART;
	else if (c == '.') state = INT_DOT;
	else if (c == 'e') state = EXP_SYM;
	else if (c == ' ') state = SUFFIX_SPACE;
	else state = ERROR;
	return state;
}
enum NumState int_dot_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = DECI_PART;
	else if (c == 'e') state = EXP_SYM;
	else if (c == ' ') state = SUFFIX_SPACE;
	return state;
}
enum NumState no_int_dot_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = DECI_PART;
	return state;
}
enum NumState deci_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = DECI_PART;
	else if (c == 'e') state = EXP_SYM;
	else if (c == ' ') state = SUFFIX_SPACE;
	return state;
}
enum NumState exp_sym_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = EXP_INT;
	else if (c == '+' || c == '-') state = EXP_SIGN;
	return state;
}
enum NumState exp_sign_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = EXP_INT;
	return state;
}
enum NumState exp_int_fsm(char c) {
	enum NumState state = ERROR;
	if (c >= '0' && c <= '9') state = EXP_INT;
	else if (c == ' ') state = SUFFIX_SPACE;
	return state;
}
enum NumState suffix_space_fsm(char c) {
	if (c == ' ') return SUFFIX_SPACE;
	return ERROR;
}
enum NumState error_fsm(char c) {
	return ERROR;
}

bool isNumber(char* s) {
	enum NumState state = PREFIX_SPACE;
	typedef enum NumState (*FSM_FUN)(char);
	FSM_FUN fsms[] = {
		prefix_space_fsm,
		sign_fsm,
		int_fsm,
		no_int_dot_fsm,
		int_dot_fsm,
		deci_fsm,
		exp_sym_fsm,
		exp_sign_fsm,
		exp_int_fsm,
		suffix_space_fsm,
		error_fsm
	};
	while (*s != '\0') {
		state = fsms[state](*s);
		if (state == ERROR) return false;
		s++;
	}
	if (state == INT_PART || state == INT_DOT || state == DECI_PART || state == EXP_INT || state == SUFFIX_SPACE)
		return true;
	return false;
}
