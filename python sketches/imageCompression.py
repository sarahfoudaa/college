from skimage import io
from sklearn.cluster import KMeans
import numpy as np
print('pppppppp')
image = io.imread('dog_backpack.png')
io.imshow(image)
io.show()
print('1')

rows = image.shape[0]
print('2')
cols = image.shape[1]
print('3')
image = image.reshape(image.shape[0]*image.shape[1],3)
print('4')
kmeans = KMeans(n_clusters =128, n_init = 10,max_iter=200)
print('4')
kmeans.fit(image)

clusters = np.asarray(kmeans.cluster_centers_,dtype = np.uint8)
labels = np.asarray(kmeans.labels_,dtype = np.uint8)
labels = labels.reshape(rows,cols)

np.save('codebook_dog.npy',clusters)
print('saved')
io.imsave('compressed_dog.png',labels)
print('compressed')

