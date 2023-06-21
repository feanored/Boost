#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
/*
* @title Biblioteca de funções de ordenação
* @author Eduardo Galvani Massino
*/

template <class T>
void trocar(T *xp, T *yp) {
	T aux; // o dobro da perfomance de alocar memória
	aux = *xp;
	*xp = *yp;
	*yp = aux;
}

template <class T>
void bubbleSort(T arr[], int n) {
	int i, j;
	for (j=n-1; j>=1; j--) {
		for (i=0; i<j; i++) {
			if (arr[i+1] < arr[i])
				trocar(&arr[i+1], &arr[i]);
		}
	}
}

template <class T>
int indexOfMin(T arr[], int low, int high) {
	int j_min;
	T min;

	min = arr[low];
	j_min = low;
	for (int i=low+1; i<=high; i++) {
		if (arr[i] < min) {
			min = arr[i];
			j_min = i;
		}
	}

	return j_min;
}

template <class T>
void selectionSort(T arr[], int n) {
	int i, j_min;

	for(i = 0; i < n; i++) {
		j_min = indexOfMin(arr, i, n-1);
		trocar(&arr[i], &arr[j_min]);
	}
}

template <class T>
void merge(T arr[], int low, int mid, int high) {
	int i, j, k, n, m;
	T *merged;

	n = high - low + 1;
	merged = new T[n];
	i = low;
	j = mid+1;
	k = 0;

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			merged[k] = arr[i];
			i++;
			k++;
		} else /*if (arr[j] < arr[i])*/ {
			merged[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		merged[k] = arr[i];
		i++;
		k++;
	}
	while (j <= high) {
		merged[k] = arr[j];
		j++;
		k++;
	}

	// copia o array ordenado para o original
	for (k = 0, m = low; k < n; k++, m++) 
		arr[m] = merged[k];

	delete[] merged;
}

template <class T>
void mergeSort(T arr[], int low, int high) {
	int mid;
	if (low == high)
		return;
	else {
		mid = (low+high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}