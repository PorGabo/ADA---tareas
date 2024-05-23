//mediana con quicksort, orden n log n

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& vector, int inicio, int fin) 
{
  int pivot = vector[fin];
  int i = (inicio - 1);

  for (int j = inicio; j < fin; j++) 
  {
    if (vector[j] <= pivot) 
    {
      i++;
      swap(vector[i], vector[j]);
    }
  }

  swap(vector[i + 1], vector[fin]);
  return (i + 1);
}

void quicksort(vector<int>& vector, int inicio, int fin) {
  if (inicio < fin) {
    int indicePivote = partition(vector, inicio, fin);
    cout << "'indice piv' : " << indicePivote << endl;

    cout << "Arr after partition: ";
    for (int i = inicio; i <= fin; i++) {
      cout << vector[i] << " ";
    }
    cout << endl;

    quicksort(vector, inicio, indicePivote - 1);
    quicksort(vector, indicePivote + 1, fin);
  }
}

int median(vector<int>& vector)
{
  int longitud = vector.size();
  cout << "Tamanio del vector: " << longitud << "\n\n";
  quicksort(vector, 0, longitud - 1);
  float mediana;
  if (longitud % 2 == 0)
  {
    mediana = (vector[longitud / 2] + vector[longitud / 2 + 1]) / 2.0;
  }
  else
  {
    mediana = vector[longitud / 2];
  }
  return mediana;
}

int main()
{
  vector<int> vector = {11,10,9,8,7,6,5,4,3};
  float mediana = median(vector);
  cout << "\nLa mediana es: " << mediana << endl;

  return 0;
}
