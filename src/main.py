#%%
from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt
import inspect

current_path = Path('..')
data_dir = current_path / 'data'
plots_dir = current_path / 'plots'
quicksort_fn = data_dir / 'quicksortData.csv'
mergesort_fn = data_dir / 'mergesortData.csv'
#%%
quicksort_data = pd.read_csv(quicksort_fn)
mergesort_data = pd.read_csv(mergesort_fn)
quicksort_data = quicksort_data.loc[quicksort_data['vectorLength'] > 2]

#%%
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle("Mergesort", fontsize=16, fontweight='bold')
width = 1.25
num_samples = 20
import numpy as np
int_linspace = list(set(list(map(int, np.linspace(1, max(mergesort_data['vectorLength']), num_samples)))))
criterion = [x in int_linspace for x in mergesort_data['vectorLength']]
sample_mergesort_data = mergesort_data[criterion].reset_index(drop=True)
ax.bar(
    sample_mergesort_data['vectorLength'] - width / 2,
    sample_mergesort_data['actualNumComparisons'],
    alpha=0.5,
    color='blue',
    label='actual',
    width=width
)
ax.bar(
    sample_mergesort_data['vectorLength'] + width / 2,
    sample_mergesort_data['expectedNumComparisons'],
    alpha=0.5,
    color='green',
    label='expected',
    width=width
)
ax.set_xticks(int_linspace)
ax.set_xlabel("Number of Elements\n(only a few are showed in the graph)")
ax.set_ylabel("Number of Comparisons", fontsize=14)
ax.legend()
fig.savefig(plots_dir / 'mergesort.png')

#%%
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle("Quicksort", fontsize=16, fontweight='bold')
width = 1.25
num_samples = 20
import numpy as np
int_linspace = list(set(list(map(int, np.linspace(1, max(quicksort_data['vectorLength']), num_samples)))))
criterion = [x in int_linspace for x in quicksort_data['vectorLength']]
sample_quicksort_data = quicksort_data[criterion].reset_index(drop=True)
ax.bar(
    sample_quicksort_data['vectorLength'] - width / 2,
    sample_quicksort_data['actualAverageNumComparisons'],
    alpha=0.5,
    color='blue',
    label='actual',
    width=width
)
ax.bar(
    sample_quicksort_data['vectorLength'] + width / 2,
    sample_quicksort_data['expectedAverageNumComparisons'],
    alpha=0.5,
    color='green',
    label='expected',
    width=width
)
ax.set_xticks(int_linspace)
ax.set_xlabel("Number of Elements\n(only a few are showed in the graph)")
ax.set_ylabel("Average Number of Comparisons", fontsize=14)
ax.legend()
fig.savefig(plots_dir / 'quicksort_comparisons.png')

#%%
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle("Quicksort", fontsize=16, fontweight='bold')
width = 1.25
num_samples = 20
import numpy as np
int_linspace = list(set(list(map(int, np.linspace(1, max(quicksort_data['vectorLength']), num_samples)))))
criterion = [x in int_linspace for x in quicksort_data['vectorLength']]
sample_quicksort_data = quicksort_data[criterion].reset_index(drop=True)
ax.bar(
    sample_quicksort_data['vectorLength'] - width / 2,
    sample_quicksort_data['actualAverageNumSwaps'],
    alpha=0.5,
    color='blue',
    label='actual',
    width=width
)
ax.bar(
    sample_quicksort_data['vectorLength'] + width / 2,
    sample_quicksort_data['expectedAverageNumSwaps'],
    alpha=0.5,
    color='green',
    label='expected',
    width=width
)
ax.set_xticks(int_linspace)
ax.set_xlabel("Number of Elements\n(only a few are showed in the graph)")
ax.set_ylabel("Average Number of Swaps", fontsize=14)
ax.legend()
fig.savefig(plots_dir / 'quicksort_swaps.png')

#%%
# assert sample_quicksort_data.shape[0] == sample_quicksort_data.shape[0]
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle("Quicksort vs Mergesort", fontsize=16, fontweight='bold')
width = 1.25
num_samples = 20
ax.bar(
    sample_quicksort_data['vectorLength'] - width / 2,
    sample_quicksort_data['actualAverageNumComparisons'],
    alpha=0.5,
    color='blue',
    label='quicksort',
    width=width
)
ax.bar(
    sample_mergesort_data['vectorLength'] + width / 2,
    sample_mergesort_data['actualNumComparisons'],
    alpha=0.5,
    color='green',
    label='mergesort',
    width=width
)
ax.set_xticks(int_linspace)
ax.set_xlabel("Number of Elements\n(only a few are showed in the graph)")
ax.set_ylabel("Average Number of Comparisons", fontsize=14)
ax.legend()
fig.savefig(plots_dir / 'quicksort_vs_mergesort.png')

# %%

# %%

# %%

# %%
