#!/usr/bin/env node

function merge(array, left, right, lSize, rSize) {
    let i = 0;
    let j = 0;
    let k = 0;

    while (i < lSize && j < rSize) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < lSize) {
        array[k] = left[i]
        k++;
        i++;
    }
    while(j < rSize) {
        array[k] = right[j];
        k++;
        j++;
    }
    console.log(array)
}

function MergeSort(array, size) {
    if (size < 2) return;

    let mid = Math.floor(size / 2);
    let left = array.slice(0, mid);
    let right = array.slice(mid, size);

    console.log(array)
    console.log(left)
    console.log(right)
    console.log("*****")
    MergeSort(left, mid);
    MergeSort(right, size - mid);
    merge(array, left, right, mid, size - mid);
}

MergeSort([19, 48, 99, 71, 13, 52, 96, 73, 86, 7], 10);
