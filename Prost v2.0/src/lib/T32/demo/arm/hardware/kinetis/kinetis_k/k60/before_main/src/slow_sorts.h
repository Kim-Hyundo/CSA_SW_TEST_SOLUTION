
struct slow_sort_ptrs {
	void (*isort)(uint32_t *array, uint32_t len);
	void (*selsort)(uint32_t *array, uint32_t len);
	void (*bubblesort)(uint32_t *array, uint32_t len);
};
