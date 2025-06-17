import matplotlib.pyplot as plt
import seaborn as sns

fig,axes = plt.subplots(1, 3, figsize = (15, 4))

sns.histplot(ax = axes[0], data=df, x = "age", kde = True, bins = 20);
sns.histplot(ax = axes[1], data=df, x = "avg_glucose_level", kde = True, bins = 20);
sns.histplot(ax = axes[2], data=df, x="bmi", kde=True, bins=20)
plt.show();
