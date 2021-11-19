#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL){
    	this -> pFirstNode = NULL;
    	this -> size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int tam = -1;
    if(this != NULL){
    	tam = this -> size;
    }
    return tam;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this -> pFirstNode;

		for(int i=0; i < nodeIndex; i++){
			pNode = pNode -> pNextNode;
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* node;
	Node* preNode;
	Node* nextNode;
	Node* firstNode;
    int retorno = -1;

    if(this!=NULL && (nodeIndex>=0 && nodeIndex<=ll_len(this)))
    {
        node= (Node*)malloc(sizeof(Node));

        if(node!=NULL)
        {
        	node->pElement= pElement;
        	node->pNextNode= NULL;

            preNode= getNode(this,nodeIndex-1);
            nextNode = getNode(this, nodeIndex+1);
            firstNode = this -> pFirstNode;

            if(preNode == NULL)
            {
                node->pNextNode = firstNode;
                this->pFirstNode = node;
            }else
            {
                node->pNextNode = nextNode;
                preNode->pNextNode = node;
            }

            this->size++;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno = -1;
    return addNode(this,nodeIndex,pElement);
    return retorno;
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

		int retorno = -1;
		int index;

		if(this!= NULL){
				index = ll_len(this);

				if(index != -1){
					retorno = addNode(this, index, pElement);
				}
		}
	    return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* pNode;
    void* retorno = NULL;

    if(this!= NULL && (index>=0 && index < ll_len(this))){

    	pNode = getNode(this,index);

    	if(pNode != NULL){
    		retorno = pNode -> pElement;
    	}

    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	Node* pNode;
    int retorno = -1;

    if(this!=NULL && (index>=0 && index<ll_len(this))){
    	pNode = getNode(this, index);

    	if(pNode != NULL){
    		pNode -> pElement = pElement;
    		retorno = 0;
    	}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	Node* pNode;
	Node* preNode;
    int retorno = -1;
	if(this != NULL && (index >= 0 && index < ll_len(this))){
		pNode = getNode(this, index);

		if(pNode != NULL){
			preNode = getNode(this, index-1);

			if(index == 0){
				this -> pFirstNode = pNode -> pNextNode;
			}
			else{
				preNode -> pNextNode = pNode -> pNextNode;
			}
			free(pNode);
			this -> size--;
			retorno = 0;
		}

	}


    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//ll_clear PENSAR
int ll_clear(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL){
    	for(int i = 0; i<ll_len(this) ; i++){
    		retorno = ll_remove(this, i);
    		if(retorno == -1){
    			break;
    		}
    	}
    	retorno = 0;
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL){
    	retorno = ll_clear(this);
    	if(retorno != -1){
        	free(this);
    	}
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	void* auxElement;
    int retorno = -1;

    if(this != NULL){

    	auxElement = NULL;

    	for(int i=0; i<ll_len(this); i++){
    		auxElement = ll_get(this, i);

    		if(auxElement == pElement){
    			retorno = i;
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;
    int lenght;

    if(this != NULL){
    	retorno = 0;
    	lenght = ll_len(this);

    	if(lenght <= 0){
    		retorno = 1;
    	}
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_push(LinkedList* this, int index, void* pElement)
{
	Node* pNode;
    int retorno = -1;

    if(this != NULL && (index >= 0 && index <= ll_len(this))){
    	pNode = (Node*)malloc(sizeof(Node));

    	if(pNode != NULL){
    		retorno = addNode(this, index, pElement);
    	}
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;

    if(this != NULL && (index >=0 && index < ll_len(this))){
    	retorno = ll_get(this,index);
    	ll_remove(this, index);
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
// INDEX OF
int ll_contains(LinkedList* this, void* pElement)
{
	void* auxElement;

    int retorno = -1;

    if(this != NULL){
    	retorno = 0;
    	for(int i =0; i < ll_len(this); i++){
    		auxElement = ll_get(this, i);
    		if(auxElement == pElement){
    			retorno = 1;
    		}
    	}


    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    int contadorCoincidencias = 0;
    int control;
    void* auxElement;

    if(this!=NULL && this2 != NULL){
    	auxElement = NULL;
    	retorno = 0;

    	for(int i=0; i<ll_len(this2); i++){
    		auxElement = ll_get(this, i);
    		if(auxElement != NULL){
    			control = ll_contains(this, auxElement);
    			    if(control != -1){
    			    	contadorCoincidencias++;
    			    }
    		}
    		if(contadorCoincidencias == ll_len(this2)){
    			retorno =1;
    			 break;
    		}
    	}
    }
    return retorno;
 }


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(this!=NULL && (from >= 0 && to <= ll_len(this)) && (to > from || to < ll_len(this))){
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL){
    		pElement = NULL;

    		for(int i=from; i<to; i++){

    			pElement = ll_get(this,i);
    			ll_add(cloneArray,pElement);

    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clonedArray = NULL;
    void* pElement;

    if(this != NULL){
    	clonedArray = ll_newLinkedList();

    	if(clonedArray != NULL){
    		pElement = NULL;

    		for(int i=0; i<=ll_len(this);i++){
        		pElement = ll_get(this, i);
        		ll_add(clonedArray, pElement);
    		}

    	}
    }
    return clonedArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno = -1;
    void* pAux;
    void* elementoI;
    void* elementoJ;

    int control1;
    int control2;
    int huboErrores = -1;

    if( this != NULL && pFunc != NULL && (order >= 0 && order <= 1) )
    {
    	retorno = 0;
        for(int i=0; i< ll_len(this)-1 ; i++)
        {
            for(int j= i+1; j < ll_len(this); j++)
            {
            	elementoI= ll_get(this,i);
                elementoJ= ll_get(this,j);
                pAux = elementoI;

                if(order == 1 && pFunc(elementoI,elementoJ) > 0)
                {
                    control1 = ll_set(this, i, elementoJ);
                    control2 = ll_set(this, j, pAux);
                }

                if(order == 0 && pFunc(elementoI, elementoJ) < 0)
                {
                	control1 = ll_set(this, i, elementoJ);
                    control2 = ll_set(this, j, pAux);
                }


                if(control1 == -1 || control2 == -1){
                	huboErrores = 0;
                	break;
                }
            }

            if(huboErrores == 0){
            	retorno = -1;
            	break;
            }
        }


    }

    return retorno;

}

