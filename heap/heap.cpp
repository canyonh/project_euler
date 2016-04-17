in_type extract_min(priority_queue *q)
{
	int min = -1;
	if (q->count <= 0)
		return -1;
	else
	{
		min = q->q[1];
		q=>q[1] = q->q[q->count];
		--q->count;
		bubbble_down(q, 1);
	}
}

void bubble_down(priority_queue *q, int index)
{
	c  = pq_young_child(p);
	min_index = p;

	for (i = 0; i <= 1; ++i)
	{
		if ((c+i) <= q->n)
		{
			if (q->q[min_index] > q->q[c+i])
				min_index = c + i;
		}
	}
