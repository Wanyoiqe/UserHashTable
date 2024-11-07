class UserHashTable:
    def __init__(self, size=100):
        # Initialize the hash table with empty lists for each bucket
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, username):
        # Compute the hash index based on the username
        return hash(username) % self.size

    def add_user(self, username: str, profile_data: dict):
        # Find the index for the username
        index = self._hash(username)
        # Check if username already exists in the chain
        for i, (user, data) in enumerate(self.table[index]):
            if user == username:
                # Update profile data if username already exists
                self.table[index][i] = (username, profile_data)
                return
        # If not found, append new username and profile_data
        self.table[index].append((username, profile_data))

    def get_user(self, username: str) -> dict:
        # Find the index for the username
        index = self._hash(username)
        # Search for the username in the chain at that index
        for user, data in self.table[index]:
            if user == username:
                return data  # Return profile data if found
        return None  # Return None if user not found
