from sklearn.neighbors import BallTree
import numpy as np
import pandas as pd

class NNSearch():
    def __init__(self, locs_df, kNN):
        """
        Initialises a NNSearch object

        locs_df = Dataframe of hotel locations \\
        kNN     = Number of nearest neighbours
        """
        self.locs = locs_df
        self.k = kNN
        self.locs[['latitude', 'longitude']] = np.deg2rad(self.locs[['latitude', 'longitude']].values)
        self.locs['NN'] = None

        self._build_tree()
        self._populate_nns()
    
    def _build_tree(self):
        """Builds the tree of hotel locations"""
        #use ball tree over kd-tree because positions cannot be treated as euclidian due to cyclic nature of lat/long
        self.tree = BallTree(np.deg2rad(self.locs[['latitude', 'longitude']].values),
         metric='haversine')
    
    def _query_point(self, point, id):
        """
        Finds the k nearest neighbours of the provided point
        
        Assumes that the point is in the tree
        """
        #need to do k+1 since target point is in the tree
        nn = [self.locs.index[i] for i in (self.tree.query([point], k = self.k + 1))[1][0]]
        if id in nn:
            nn.remove(id) #only expect one occurence of id

        return nn

    def _populate_nns(self):
        """Populate the dataframe with nearest neighbours for each hotel"""
        nns = [self._query_point([lat, long], id) for id, lat, long in \
            zip(self.locs.index, self.locs['latitude'], self.locs['longitude'])]
        self.locs.NN = nns

def main():
    # Read in hotel data from csv, or other file types as needed
    locs_df = pd.read_csv('hotels_data.csv', index_col='hotel_id', delimiter=',')
    # Create the tree and calculate nearest neighbours - time completity should be O(Nlog(N)^2) which is construction time of ball tree
    # Since for each hotel we have 
    nn_tree = NNSearch(locs_df)
    out_df = nn_tree.locs
    #Can then search for the needed hotels as necessary



